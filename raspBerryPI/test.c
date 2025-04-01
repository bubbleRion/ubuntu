#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//gpio pin
#define LED 23  // BCM GPIO 23

int main(void) {
    int fd;

    // 1. GPIO 23 활성화
    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
        perror("Error exporting GPIO");
        return 1;
    }
    write(fd, "23", 2);
    close(fd);

    // 2. 방향 설정 (out)
    sleep(1); // 시스템이 GPIO를 설정할 시간을 줌
    fd = open("/sys/class/gpio/gpio23/direction", O_WRONLY);
    if (fd < 0) {
        perror("Error setting direction");
        return 1;
    }
    write(fd, "out", 3);
    close(fd);

    // 3. LED 깜빡이기
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

    // 4. GPIO 23 비활성화
    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd < 0) {
        perror("Error unexporting GPIO");
        return 1;
    }
    write(fd, "23", 2);
    close(fd);

    return 0;
}
