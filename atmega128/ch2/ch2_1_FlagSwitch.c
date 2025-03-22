#include <avr/io.h>
#include <avr/delay.h>

int main()
{
    unsigned char flag_switch = 0;
    DDRC = 0x0F;
    PORTE = _BV(2);
    PORTC = 0x01;
    while(1){
        if(PINE >> 2){
            flag_switch = PINE >>2;
        }
        if(!(flag_switch & _BV(PC0))){
            PORTC ^= 0x0F;
        }
        else{
            PORTC = 0x01 ;
        }
        // PORTC ^= 0x01;
        // _delay_ms(500);
    }
    return 0;
}