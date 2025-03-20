// uart를 이용해서 시리얼 통신으로 센서 값을 0.1초 간격으로 출력하세요.
// CDS ADC_data : xxxx

#include <stdio.h>
#include "lcd.h"
#include "uart0.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

volatile uint16_t adcResult = 0;

int main()
{   
    uart0Init();
    lcdInit(); 
    stdin = &INPUT;
    stdout = &OUTPUT;

    ADMUX = 0x40;
    ADCSRA = 0xAF;
    ADCSRA |= 0x40;
    sei();
    lcdGotoXY(0,0);
    lcdPrintData("Light Sensor" , 12);
    char buffer[16];
    while (1)
    {
        lcdGotoXY(0,1);
        sprintf(buffer , "L : %u" , adcResult);
        lcdPrintData(buffer, strlen(buffer));
        printf("\n\rCDS ADC_data : %u" , adcResult);
        _delay_ms(200);
    }
    return 0;

}

ISR(ADC_vect){
    cli();
    adcResult = ADC;
    sei();
}