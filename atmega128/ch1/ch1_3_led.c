#include <avr/io.h>
#include <avr/delay.h>

int main()
{
    while(1){
        unsigned char led_data = 0x08;
        unsigned int count = 0;
        while(1){
            PORTC = led_data;
            if(count % 6 < 3){
                led_data /= 0x02;
                count++;
            }
            else{
                led_data *= 0x02;
                count++;
            }
            if(count >= 6){
                count = 0;
            }
            _delay_ms(500);
        }
    }
    return 0;
}