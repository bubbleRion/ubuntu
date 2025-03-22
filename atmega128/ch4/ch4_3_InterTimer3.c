#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
volatile uint8_t timeS = 0x01;
volatile uint8_t fndFlag = 0, edgeFlag = 0;
int main(void)
{

    DDRA = 0xFF;

    TCCR3A = 0x00;
    TCCR3B = 0x45; //상승 엣지 캡쳐 트리거 설정 분주비 5 == 1024
    ETIMSK = _BV(TOIE3) | _BV(TICIE3);
    ETIFR |= _BV(ICF3);
    sei();


    while (1){
        if(fndFlag){
            if(timeS > 9){
                timeS = 9;
            }
            PORTA = numbers[timeS];
            fndFlag = 0;
        }
    }
    return 0;
}
ISR(TIMER3_CAPT_vect){
    uint16_t count_check;

    if(edgeFlag == 0)
    {
        TCCR3B &= ~(1 <<ICES3);
        TCNT3 = 0;
        ICR3 = 0;
        edgeFlag = 1;
    }
    else{
        TCCR3B |= (1 <<ICES3);
        count_check = ICR3;
        timeS = count_check / 1440; // 0.1 second
        fndFlag = 1;
        edgeFlag = 0;
    }
}