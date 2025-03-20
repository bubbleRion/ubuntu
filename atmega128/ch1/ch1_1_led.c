#include <avr/io.h>
#include <util/delay.h>

int main()
{
    while (1)
    {
        DDRC = 0x03;
        // *(volatile uint8_t *)(0x14) = 0x03;
        PORTC = 0x0F;
        // PORTC |= (1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3);
        // PORTC |= _BV(PC0) | _BV(PC1) | _BV(PC2) | _BV(PC3);
        _delay_ms(1000);
        PORTC = 0x00;
        _delay_ms(1000);
    }
    return 0;
}