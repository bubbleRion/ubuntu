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
    DDRC = 0x01; // port 0번 비트 출력
    PORTE = 0xFF; // 풀업 설정
    PORTC = 0x00;
    
    while(1){
        if(milliseconds >=32){
            milliseconds = 0;
            count = (count + 1) % 10;
            PORTA = numbers[count];
        }
        
         // _delay_ms(10);
         if(!(PINE >> 2& _BV(PC0))){
            count = 0; // 버튼 반전
            //버튼이 눌릴 때 까지 대기
            
        }
    }
    return 0;
}