#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define PIEZO_PORT PORTB
#define PIEZO_DDR  DDRB
#define PIEZO_PIN  _BV(PB7)

uint16_t doReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};
uint16_t piano = 0;
// '떴다떴다 비행기' 음계
uint8_t melody[24] = {4, 4, 5, 5, 4, 4, 2, 
                    4, 4, 2, 2, 1,
                    4, 4, 5, 5, 4, 4, 2,
                    4, 2, 1, 2, 0};


int main(void) {
    // PIEZO_DDR |= PIEZO_PIN; // PB4를 출력으로 설정
    DDRB = _BV(PB7);
    TCCR1A = _BV(COM1C1) | _BV(WGM11);
    TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS00); // 0x19
    TCCR1C = 0x00;

    sei();

    while (1) {
        ICR1 = 14745600 / doReMi[melody[piano]];
        OCR1C = ICR1 / 2;
        piano++;
        if(piano > 24){
            piano = 0;
        }
        _delay_ms(300);
    }
    return 0;
}