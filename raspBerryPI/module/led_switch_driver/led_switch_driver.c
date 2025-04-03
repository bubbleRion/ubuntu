// read switch 정보 얻기, write led 조작 드라이버
// ...

/*
sudo insmod led_switch_driver.ko
dmesg
sudo rm /dev/led_switch_driver
sudo mknod /dev/led_switch_driver c 223 0
sudo chmod 666 /dev/led_switch_driver
*/
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

#define DEV_MAJOR_NUMBER 223
#define DEV_NAME "led_switch_driver"

static int led_switch_driver_open(struct inode *inode, struct file *file);
static int led_switch_driver_release(struct inode *inode, struct file *file);
static ssize_t led_switch_driver_read(struct file *file, char __user *buf, size_t length, loff_t *ofs);
static ssize_t led_switch_driver_write(struct file *file, const char __user *buf, size_t length, loff_t *ofs);

// GPIO 핀 설정 (512는 레지스터 오프셋)
static int led[4] = {23 + 512, 24 + 512, 25 + 512, 1 + 512};
static int sw[4] = {4 + 512, 17 + 512, 27 + 512, 22 + 512};

// LED 상태 저장 배열 (0: 꺼짐, 1: 켜짐)
static int led_status[4] = {0};
static int irq_num[4] = {57, 58, 59, 60};
static irqreturn_t irq_handler(int irq, void *dev_id)
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        if (irq == irq_num[i])
        {
            led_status[i] = !led_status[i]; // 현재 상태 반전 (토글)
            gpio_set_value(led[i], led_status[i]);
            printk(KERN_INFO "Button %d pressed, LED %d toggled to %d\n", i, i, led_status[i]);
            break;
        }
    }
    return IRQ_HANDLED;
}

static struct file_operations led_switch_driver_fops = {
    .owner = THIS_MODULE,
    .open = led_switch_driver_open,
    .release = led_switch_driver_release,
    .read = led_switch_driver_read,
    .write = led_switch_driver_write,
};

static int led_switch_driver_init(void)
{
    int i, ret;
    printk(KERN_INFO "LED Switch Driver Init!\n");

    // 문자 디바이스 드라이버 등록
    ret = register_chrdev(DEV_MAJOR_NUMBER, DEV_NAME, &led_switch_driver_fops);
    if (ret < 0)
    {
        printk(KERN_ERR "Failed to register char device\n");
        return ret;
    }

    // GPIO 및 IRQ 요청
    for (i = 0; i < 4; ++i)
    {
        ret = gpio_request(led[i], "LED");
        if (ret < 0)
            printk(KERN_ERR "LED %d request failed\n", i);

        gpio_direction_output(led[i], 0); // LED 초기 상태 OFF

        ret = gpio_request(sw[i], "Switch");
        if (ret < 0)
            printk(KERN_ERR "Switch %d request failed\n", i);

        gpio_direction_input(sw[i]); // 스위치 입력 모드 설정

        // GPIO 번호를 IRQ 번호로 변환
        irq_num[i] = gpio_to_irq(sw[i]);

        // IRQ 요청 (RISING: 버튼 눌릴 때 감지)
        ret = request_irq(irq_num[i], (irq_handler_t)irq_handler, IRQF_TRIGGER_RISING, "IRQ", NULL);
        if (ret < 0)
            printk(KERN_ERR "IRQ %d request failed\n", i);
    }

    return 0;
}

static void led_switch_driver_exit(void)
{
    int i;
    printk(KERN_INFO "LED Switch Driver Exit!\n");

    unregister_chrdev(DEV_MAJOR_NUMBER, DEV_NAME);

    for (i = 0; i < 4; ++i)
    {
        free_irq(irq_num[i], NULL);
        gpio_free(sw[i]);
        gpio_free(led[i]);
    }
}

static int led_switch_driver_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "LED Switch Driver Opened!\n");
    return 0;
}

static int led_switch_driver_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "LED Switch Driver Closed!\n");
    return 0;
}

// 스위치 상태 읽기
static ssize_t led_switch_driver_read(struct file *file, char __user *buf, size_t length, loff_t *ofs)
{
    int i, ret;
    char read_buf[4];

    printk(KERN_INFO "LED Switch Driver Read!\n");

    for (i = 0; i < 4; ++i)
        read_buf[i] = gpio_get_value(sw[i]);

    ret = copy_to_user(buf, read_buf, sizeof(read_buf));
    if (ret < 0)
        printk(KERN_ERR "Switch driver copy to user fail!\n");

    return sizeof(read_buf);
}

// LED 상태 변경 (수동 조작)
static ssize_t led_switch_driver_write(struct file *file, const char __user *buf, size_t length, loff_t *ofs)
{
    int i, ret;
    unsigned char cbuf[4];

    ret = copy_from_user(cbuf, buf, length);
    if (ret < 0)
    {
        printk(KERN_ERR "Copy from user error!\n");
        return -EFAULT;
    }

    printk(KERN_INFO "LED Driver Write!\n");

    for (i = 0; i < 4; ++i)
    {
        gpio_set_value(led[i], cbuf[i]);
        led_status[i] = cbuf[i]; // LED 상태 업데이트
    }

    return length;
}

module_init(led_switch_driver_init);
module_exit(led_switch_driver_exit);
MODULE_LICENSE("GPL");