#include "lcd.h"           // 추가: lcd 라이브러리 포함
#include "at25160.h"           // 추가: lcd 라이브러리 포함
#include <avr/interrupt.h> // AVR 인터럽트에 대한 헤더파일
#include <avr/io.h>        //AVR 입출력에 대한 헤더 파일
#include <stdio.h>         // 추가: sprintf 사용
#include <string.h>        // 추가: strlen 사용
#include <util/delay.h>    // delay 함수사용을 위한 헤더파일

#define ARRAY_SIZE(array) ((sizeof(array)) / sizeof(array[0]))

uint8_t msg1[] = "welcome!!";
uint8_t msg2[] = "Atmega128_world!!";
uint8_t msg3[] = "SPI-flash Example";


int main(void)
{
    uint8_t i =  0;
    uint8_t buf1[20] = {0};
    uint8_t buf2[20] = {0};
    uint8_t buf3[20] = {0};
    SPI_Init();
    lcdInit();

    at25160_Write_Arry(0x0100 , msg1 , ARRAY_SIZE(msg1));
    at25160_Write_Arry(0x0200 , msg2 , ARRAY_SIZE(msg2));
    at25160_Write_Arry(0x0300 , msg3 , ARRAY_SIZE(msg3));

    at25160_Read_Arry(0x100 , buf1 , ARRAY_SIZE(buf1));
    at25160_Read_Arry(0x200 , buf2 , ARRAY_SIZE(buf2));
    at25160_Read_Arry(0x300 , buf3 , ARRAY_SIZE(buf3));


    while (1)
    {
        for(int i = 0; i < ARRAY_SIZE(msg1) - 1; i++){
            lcdGotoXY(0,0);
            lcdDataWrite(buf1[i]);
            _delay_ms(100);
        }
        int i = 0;
        lcdGotoXY(0,1);
        while(buf2[i]){
            lcdDataWrite(buf1[i]);
            ++i;
            _delay_ms(100);
        }
            lcdGotoXY(0,0);
            lcdDataWrite(buf3[i]);
            _delay_ms(2000);
            lcdClear();
    }
    return 0;
}

