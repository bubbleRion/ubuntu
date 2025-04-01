#include "lcd.h"           // 추가: lcd 라이브러리 포함
#include <avr/interrupt.h> // AVR 인터럽트에 대한 헤더파일
#include <avr/io.h>        //AVR 입출력에 대한 헤더 파일
#include <stdio.h>         // 추가: sprintf 사용
#include <string.h>        // 추가: strlen 사용
#include <util/delay.h>    // delay 함수사용을 위한 헤더파일



int main(void)
{
    uint8_t pwmDuty = 60 , cntDir = 0;
    DDRD = _BV(PD4) | _BV(PD5);
    DDRB = _BV(PB5);
    TCCR1A = _BV(COM1A1) | _BV(WGM11);
    TCCR1B = _BV(CS11) | _BV(WGM12) | _BV(WGM13);

    ICR1 = 800;
    OCR1A = 8 * pwmDuty; // 800 카운트 하는데 560번까지 -> 5V 70%
    
    lcdInit();
    lcdGotoXY(0,0);
    lcdPrintData("Duty" , 7);

    PORTD |= _BV(PD5); // M1 역회전
    PORTB |= _BV(PB5);

    while (1)
    {
        if(cntDir){
            pwmDuty--;
            if(pwmDuty < 1){
                cntDir = 0;
            }
        }
        else{
            pwmDuty++;
            if(pwmDuty > 99){
                cntDir = 1;
            }
        }
        _delay_ms(50);
        OCR1A = 8 * pwmDuty; // 0~100
        lcdGotoXY(7,0);
        lcdDataWrite((pwmDuty/10) % 10 + '0');
        lcdDataWrite((pwmDuty) % 10 + '0');
        lcdDataWrite('%');
    }
    return 0;
}

