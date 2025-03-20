#include <avr/interrupt.h>
#include <avr/io.h>

volatile uint8_t ledData = 0x08;
uint8_t timer0Cnt = 0;
uint8_t timer2Cnt = 0;
volatile unsigned int count = 0;

// ISR(TIMER0_OVF_vect)
ISR(TIMER2_OVF_vect);

int main(void)
{
    DDRC = 0x0F;

    TCCR2 = 0x05;
    TCNT2 = 46;
    TIMSK = _BV(TOIE2);
    TIFR |= _BV(TOV2);
    sei();
    while (1)
    {
        
        if (timer2Cnt == 30)
        {
            if(count % 6 < 3){
                ledData /= 0x02;
                count++;
            }
            else{
                ledData *= 0x02;
                count++;
            }
            if(count >= 6){
                count = 0;
            }
            timer2Cnt = 0;
        }
        PORTC = ledData;

    }
}

ISR(TIMER2_OVF_vect)
{
    cli();
    TCNT0 = 46; // 113, 114 .... 255 .. 144-> 0.0025 초
    timer2Cnt++;
    sei();
}