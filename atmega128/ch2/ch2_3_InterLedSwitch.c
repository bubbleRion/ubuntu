#include <avr/io.h>
// #include <avr/delay.h>
#include <avr/interrupt.h>
volatile unsigned long milliseconds = 0;

// 밀리초 단위 업데이트
ISR(TIMER0_OVF_vect){
    ++milliseconds;
}

// 타이머 제로 기본설정
void timer0_init(void){
    TCCR0 = _BV(CS01) | _BV(CS00);
    TCNT0 = 6;
    TIMSK |= _BV(TOIE0);
    sei();
}

int main()
{
    timer0_init();
    DDRC = 0x01; // C 0 bit setting
    PORTE = 0xFF; // full up setting
    unsigned long lastDebounceTime = 0;
    const unsigned long debounceDelay = 20;
    uint8_t lastButtonState = 1;
    uint8_t buttonState = 1;
    PORTC = 0x00;
    while (1)
    {
        uint8_t reading = PINE & _BV(PE2);
        // 버튼 상태 변경 확인
        if(reading != lastButtonState){
            lastDebounceTime = milliseconds;
        }
        //디바운스 시간 경과 확인
        if((milliseconds - lastDebounceTime)> debounceDelay)
        {
            //실제 버튼 상태 업데이트
            if(reading != buttonState){
                buttonState = reading;
                // 버튼이 눌렸을 때 동작 수행
                if(buttonState == 0){
                    PORTC ^= _BV(PC0);
                }
            }
        }
        // 마지막 상태 저장
        lastButtonState = reading;
    }
    
    return 0;
}