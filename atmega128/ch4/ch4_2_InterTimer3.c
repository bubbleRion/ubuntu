#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
volatile uint8_t ledData = 0x01;
volatile uint8_t shift;
int main(void)
{

    DDRC = 0x0F;
    TCCR3A = 0x00;
    TCCR3B =  _BV(CS32);
    TCNT3 = 46786; 

    ETIMSK = _BV(TOIE3);

    sei();


    while (1){
        _delay_ms(100);
    }
    return 0;
}
ISR(TIMER3_OVF_vect){
    cli();
    if(ledData >= 0x08){
        shift = 0;
    }
    if(ledData == 0x01){
        shift = 1;
    }
    if(shift){
        ledData <<= 1;
    }
    else{
        ledData >>= 1;
    }
    PORTC = ledData;
    // timer1Cnt = 0;
    sei();
}