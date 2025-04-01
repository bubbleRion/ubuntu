#include "lcd.h"           // 추가: lcd 라이브러리 포함
#include <avr/interrupt.h> // AVR 인터럽트에 대한 헤더파일
#include <avr/io.h>        //AVR 입출력에 대한 헤더 파일
#include <stdio.h>         // 추가: sprintf 사용
#include <string.h>        // 추가: strlen 사용
#include <util/delay.h>    // delay 함수사용을 위한 헤더파일

volatile unsigned int ADC_result = 0;

int main(void)
{
    DDRD = _BV(PD4) | _BV(PD5);
    DDRB = _BV(PB5);

    while (1)
    {
        PORTD = _BV(PD4); // M1 정회전
        PORTB = _BV(PB5); // M1 회전
        _delay_ms(500);
        PORTD = _BV(PD4) & 0xEF;
        PORTD |= _BV(PD5);
        PORTB |= _BV(PB5);
        _delay_ms(500);
    }
    return 0;
}

