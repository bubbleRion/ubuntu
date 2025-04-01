#include <stdio.h>
// #include <wiringPi.h>
#include <unistd.h>
#include "fcntl.h"
#include <string.h>

//gpio pin
#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1
int main(void){
    // wiringPiSetupGpio(); //bcm 기준 gpio 핀
    int fd;

    // 1. GPIO 23 활성화
    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
        perror("Error exporting GPIO");
        return 1;
    }
    write(fd, "23", 2);
    close(fd);
    sleep(1); // 시스템이 GPIO를 설정할 시간을 줌
    fd = open("/sys/class/gpio/gpio23/direction", O_WRONLY);
    if (fd < 0) {
        perror("Error setting direction");
        return 1;
    }
    write(fd, "out", 3);
    close(fd);
    for(int i = 0; i < 5; ++i){
        fd = open("/sys/class/gpio/gpio23/value", O_WRONLY);
        write(fd, "1", 1);
        close(fd);
        sleep(1);

        fd = open("/sys/class/gpio/gpio23/value", O_WRONLY);
        write(fd, "0", 1);
        close(fd);
        sleep(1);
    }
    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd < 0) {
        perror("Error unexporting GPIO");
        return 1;
    }
    write(fd, "23", 2);
    close(fd);

    return 0 ;
}