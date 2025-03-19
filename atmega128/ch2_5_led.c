// #define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/interrupt.h>
volatile unsigned long milliseconds = 0;

// 밀리초 단위 업데이트
ISR(TIMER0_OVF_vect){
    ++milliseconds;
}

// 타이머 제로 기본설정
void timer0_init(void){
    TCCR0 = _BV(CS02) | _BV(CS01) | _BV(CS00);
    TCNT0 = 6;
    TIMSK |= _BV(TOIE0);
    sei();
}

int main()
{
    timer0_init();
    DDRA = 0xFF; // C 0 bit setting
    
    uint8_t numbers[] = {0x3F , 0x06 , 0x5b , 0x4F , 0x66 , 0x6D , 0x7D , 0x27 , 0x7F, 0x67};
    int count = 0;

    while(1){
        if(milliseconds >=32){
            milliseconds = 0;
            count = (count + 1) % 10;
            PORTA = numbers[count];
        }
        
    }
    return 0;
}