// #define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

volatile uint8_t shift_flag = 1; // 인터럽트에서 쓸 변수


int main()
{
    uint8_t led_data = 0x01;

    DDRC = 0x0F; // 하위 비트 4개 출력
    //인터럽트 설정
    EIMSK = 0xA0; // 0b10100000 INTS , INT7
    // EICRB = 0xC8; 
    EICRB = _BV(ISC71) | _BV(ISC70) | _BV(ISC51);
    EIFR = 0xA0; //플래그 클리어
    sei();

    while(1){
        PORTC = led_data;
        if(shift_flag == 1){
            if(led_data == 0x08){
                led_data = 0x01;
            }
            else{
                led_data <<= 1;
            }
        }
        else if(shift_flag == 2){
            if(led_data == 0x01){
                led_data = 0x08;
            }
            else{
                led_data >>= 1;
            }
        }
        _delay_ms(100);
    }
    return 0;
}

SIGNAL(INT5_vect){
    cli(); // sei() 반대 설정 SREG -> I unset -> 0
    shift_flag = 1;
    sei(); // 다시 전역 선언
}

SIGNAL(INT7_vect){
    cli(); // sei() 반대 설정 SREG -> I unset -> 0
    shift_flag = 2;
    sei(); // 다시 전역 선언
}