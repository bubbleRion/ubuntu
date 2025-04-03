#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd, led_fd;
    char buf[4];
    char led_buf[4]; // LED 상태 저장 버퍼 (0: 끄기, 1: 켜기)

    // 스위치 드라이버 열기
    fd = open("/dev/led_switch_driver", O_RDONLY);
    if (fd < 0)
    {
        printf("driver open fail\n");
        return -1;
    }

    // LED 드라이버 열기 (디바이스 파일 경로 예시: /dev/led_driver)
    led_fd = open("/dev/led_switch_driver", O_WRONLY);
    if (led_fd < 0)
    {
        printf("LED driver open fail\n");
        close(fd);
        return -1;
    }

    // LED 상태 초기화 (모두 끄기)
    for (int i = 0; i < 4; ++i)
    {
        led_buf[i] = 0; // LED 상태를 모두 0 (끄기)로 설정
    }
    write(led_fd, led_buf, sizeof(led_buf)); // 초기 LED 상태 설정

    for (int i = 0; i < 10; ++i)
    {
        // 스위치 상태 읽기
        read(fd, &buf, 4);

        // 각 스위치 상태에 따라 LED 상태 변경
        for (int j = 0; j < 4; ++j)
        {
            // 스위치가 눌리면 토글
            if (buf[j] == 1) // 스위치가 눌렸을 때 (1이면 눌림)
            {
                led_buf[j] = !led_buf[j]; // 상태 반전 (토글)
            }
        }

        // LED 상태를 디바이스에 반영
        write(led_fd, led_buf, sizeof(led_buf));

        // 스위치 상태 출력
        printf("sw1: %d, sw2: %d, sw3: %d, sw4: %d\n", buf[0], buf[1], buf[2], buf[3]);

        sleep(1);
    }

    // 드라이버 파일 닫기
    close(fd);
    close(led_fd);

    return 0;
}
