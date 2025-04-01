#include <stdio.h>
#include <wiringPi.h>

//gpio pin
#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1
int main(void){
    wiringPiSetupGpio(); //bcm 기준 gpio 핀
    pinMode(LED1 , OUTPUT);
    // pinMode(LED2 , OUTPUT);
    // pinMode(LED3 , OUTPUT);
    // pinMode(LED4 , OUTPUT);
    while(1){
        digitalWrite(LED1 , HIGH);
    }
    printf("안녕하세요!\n");
    return 0 ;
}