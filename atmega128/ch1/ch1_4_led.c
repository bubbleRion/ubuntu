#include "lcd.h"
#include <avr/io.h>
#include <avr/delay.h>
#include <stdio.h>
int main()
{

    lcdInit();
    lcdClear();
    char lcdBuffer[17];

    unsigned char switch_flag = 0;
    DDRE = 0x00;
    PORTE = 0x00;
    DDRC = 0x0F;
    while(1){
        if (PINE >> 4){
            switch_flag = PINE >> 4; // 0b1000 0b0100
            
        }    
        PORTC = switch_flag;
        snprintf(lcdBuffer , sizeof(lcdBuffer) , "Hello World!0x%02X" , switch_flag);
        lcdGotoXY(0,0);
        lcdPrint(lcdBuffer);

    }
    return 0;
}