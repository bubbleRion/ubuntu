#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>


#define RGB_SERVO_I2C_ADDR 0x5e
#define PCA9685_LED_ON_L 0x06
#define PCA9685_PRESCALE 0xFE
#define PCA9685_MODE1 0x00

//switch
#define SW1 4
#define SW2 17
#define SW3 27
#define SW4 22

void i2C_init(int fd, int freq);

int main(void)
{
    
    int sw[4] = {SW1, SW2, SW3, SW4};
    int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
    i2C_init(rgb_servo_fd, 0x79); // 50 hz
    // 프리스케일 값 = (오실레이터 주파수 / (4096 * 원하는 주파수)) - 1
    // 25000000 / (4096 * (0x79 + 1))=50.028817
    srand(time(NULL)); // random 셋

    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L, 0);     // 빨간색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 4, 0); // 녹색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 8, 0); // 파란색

    // 빨간색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, 4095);
    delay(100);
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, 0);
    delay(100);

    // 녹색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, 4095);
    delay(100);
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, 0);
    delay(100);

    // 파란색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, 4095);
    delay(100);
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, 0);
    delay(100);

    // 점점 밝아지는 코드
    for (int i = 0; i < 4; ++i)
    {
        pinMode(sw[i], INPUT);
    }
    
    int zero_color = 0;
    
    while(1){

        if(digitalRead(sw[0])){
            wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L, zero_color); 
        }
        else if(digitalRead(sw[1])){
            wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 4, zero_color); // 녹색
        }
        else if(digitalRead(sw[2])){
            wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 8, zero_color); // 파란색
        }
        else{
            if(zero_color < 4095){
                zero_color += 500;
            }
        }
    }
    return 0;
}

void i2C_init(int fd, int freq)
{
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x01);    // 리셋
    delay(10);                                        // 리셋 후 대기
    wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, freq); // 주파수 설정
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);
}