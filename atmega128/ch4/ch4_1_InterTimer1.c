#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
volatile uint8_t ledData = 0x00;

ISR(TIMER1_OVF_vect);
int main(void)
{
    DDRC = 0x0F;
    
    TCCR1A = 0x00;
    TCCR1B = _BV(CS10) | _BV(CS12);

    TIMSK = _BV(TOIE1);

    sei();

    while (1);
    return 0;
}
ISR(TIMER1_OVF_vect){
    cli();
    // timer1Cnt++;
    TCNT1 = 49910;
    PORTC = ledData;
    ledData++;
    if(ledData > 0x0F){
        ledData = 0;
    }
    // timer1Cnt = 0;
    sei();
}