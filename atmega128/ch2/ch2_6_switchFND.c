// #define F_CPU 16000000L
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
volatile unsigned long milliseconds = 0;

int count_TR(uint8_t flag);

int main()
{
    uint8_t numbers[] = {0x3F , 0x06 , 0x5b , 0x4F , 0x66 , 0x6D , 0x7D , 0x27 , 0x7F, 0x67};
    int count = 0;
    uint8_t flag_switch = 0;    
    DDRA = 0xFF;
    DDRE = 0x00;

    while(1){
        flag_switch = PINE >> 4;
        while(PINE >> 4 != 0x00);
        
        if(flag_switch != 0){
            count += count_TR(flag_switch);
        }

        if(count < 0){
            count = 0;
        }
        else if(count > 10){
            count = 10;
        }

        PORTA = numbers[count];
        _delay_ms(100);
        
    }
    return 0;
}

int count_TR(uint8_t flag){
    int count = 0;
    switch (flag)
    {
    case 0x01:
        count = 1;
        break;
    case 0x02:
        count = 2;
        break;
    case 0x04:
        count = -1;
        break;
    case 0x08 :
        count = -2;
        break;
    default:
        break;
    }
    return count;
}