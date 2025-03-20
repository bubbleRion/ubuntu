#include <stdio.h>
#include "lcd.h"
#include "uart0.h"
#include <avr/interrupt.h>
#include <avr/io.h>

volatile uint8_t intData = '0';
uint8_t cursor = 0;

int main()
{   lcdInit(); 
    uart0Init();
    stdin = &INPUT;
    stdout = &OUTPUT;

    DDRE = 0x02;  // Rx(입력) Tx(출력)

    EICRB = 0xFF; //4567 상승엣지 
    EIMSK = 0xF0; // 4567허용
    EIFR  = 0xF0; // 4567 클리어

    sei(); // 전역 인터럽트 허용
    char buffer[16];
    int index = 0;
    while (1)
    {
        if(intData != '0'){
            printf("\n\r Input Switch :%c" , intData);
            intData = '0';
        }
        
        while (index < sizeof(buffer) - 1) // 버퍼 크기를 초과하지 않도록
        {
            char cData = fgetc(stdin);
            if (cData == '\n' || cData == '\r') // 엔터를 입력하면 종료
                break;

            buffer[index++] = cData;
            lcdDataWrite(cData); // LCD에 출력
        }
        buffer[index] = '\0'; // 문자열 종료
        index = 0;  // 다시 입력받을 수 있도록 초기화
        cursor++;
        if(cursor == 16){
            lcdGotoXY(0,1);
        }
        else if(cursor == 32){
            cursor = 0;
            lcdGotoXY(0,0);
        }
    }
    return 0;

}

ISR(INT4_vect){
    cli();
    intData = '1';
    sei();
}
ISR(INT5_vect){
    cli();
    intData = '2';
    sei();
}
ISR(INT6_vect){
    cli();
    intData = '3';
    sei();
}
ISR(INT7_vect){
    cli();
    intData = '4';
    sei();
}