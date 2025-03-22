#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

uint16_t doReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046}; // 음계 배열
uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F}; // FND 표시 값 (0~3)

volatile uint8_t timeS = 5;     // 버튼이 눌린 번호 (0~3)
volatile uint8_t piano = 0;     // 버튼에 해당하는 음계 번호
volatile uint8_t timer3Cnt = 0; // 타이머 카운트
volatile uint8_t playFlag = 0;  // 소리 재생 여부 플래그

int main(void)
{
    DDRA = 0xFF; // FND 출력 설정
    DDRB |= _BV(PB7); // 피에조 출력 (PB7)

    // Timer3 설정 (Fast PWM, 분주비 8)
    TCCR3A |= _BV(COM3A1) | _BV(WGM31); // Fast PWM 모드, 출력 비교 모드
    // TCCR3B = _BV(WGM13) | _BV(WGM12) | _BV(CS00); // 분주비 8, Fast PWM 모드
    TCCR3B = 0x19;
    // 인터럽트 설정
    EIMSK = 0xF0; // INT4~INT7 인터럽트 활성화
    EICRB = 0xFF; // 상승 엣지 트리거 설정 (PE4~PE7)

    sei(); // 전역 인터럽트 활성화

    while (1) {
        if (playFlag) {
            if (timeS < 4) {
                ICR3 = 14745600 / doReMi[piano]; // 주파수 설정
                OCR3A = ICR3 / 2; // 50% 듀티 사이클
                PORTA = numbers[timeS]; // FND에 버튼 번호 표시
                timer3Cnt = 20; // 2초 동안 소리 재생
                playFlag = 0; // 소리 재생 플래그 리셋
            }
        }
    }
    return 0;
}

// 버튼 인터럽트 핸들러 (PE4~PE7에 연결된 버튼)
ISR(INT4_vect) {cli(); timeS = 0; piano = 0; playFlag = 1; sei();} // 버튼 0
ISR(INT5_vect) {cli(); timeS = 1; piano = 1; playFlag = 1; sei();} // 버튼 1
ISR(INT6_vect) {cli(); timeS = 2; piano = 2; playFlag = 1; sei();} // 버튼 2
ISR(INT7_vect) {cli(); timeS = 3; piano = 3; playFlag = 1; sei();} // 버튼 3

// Timer3 오버플로우 인터럽트 핸들러
ISR(TIMER3_OVF_vect){
    if (timer3Cnt > 0) {
        timer3Cnt--;
        if (timer3Cnt == 0) {
            OCR3C = 0; // 무음 처리
            TCCR3A &= ~_BV(COM3C1); // PWM 비활성화 (무음)
        }
    }
}
