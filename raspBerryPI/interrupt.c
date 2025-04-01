#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>


//gpio pin
#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1
#define SW1 4
#define SW2 17
#define SW3 27
#define SW4 22

#define BUTTON_PIN 4  // BCM 기준
#define LED_PIN 23  // BCM 기준

void buttonPress(void) {
    printf("버튼이 눌렸습니다!\n");
    digitalWrite(LED_PIN, HIGH);
    delay(1500);
    digitalWrite(LED_PIN, LOW);
}

int main() {
    if (wiringPiSetupGpio() == -1) {
        printf("WiringPi 초기화 실패!\n");
        return 1;
    }

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    pullUpDnControl(BUTTON_PIN, PUD_UP);  // 내부 풀업 저항 설정

    // 인터럽트 설정 (Rising Edge에서 실행)
    if (wiringPiISR(BUTTON_PIN, INT_EDGE_RISING, &buttonPress) < 0) {
        printf("인터럽트 설정 실패!\n");
        return 1;
    }

    while (1) {
        delay(100);
    }

    return 0;
}
