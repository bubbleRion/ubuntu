// #define F_CPU 16000000L

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

volatile uint8_t shift_flag = 1; // 인터럽트에서 쓸 변수


int main()
{

    DDRA = 0xFF;
    //인터럽트 설정
    EIMSK = 0x20; // 0b10100000 INTS , INT7
    EICRB = _BV(ISC50) | _BV(ISC51);
    uint8_t numbers[] = {0x3F , 0x06 , 0x5b , 0x4F , 0x66 , 0x6D , 0x7D , 0x27 , 0x7F, 0x67};
    uint8_t count = 0;
    sei();

    while(1){
        if(shift_flag == 1){
            count = (count + 1) % 10;
            PORTA = numbers[count];
            _delay_ms(100);
        }
        else{
            _delay_ms(2000);
        }
        
    }
    
    return 0;
}

SIGNAL(INT5_vect){
    cli(); // sei() 반대 설정 SREG -> I unset -> 0
    shift_flag ^= 1;
    sei(); // 다시 전역 선언
}

// SIGNAL(INT7_vect){
//     cli(); // sei() 반대 설정 SREG -> I unset -> 0
//     shift_flag = 2;
//     sei(); // 다시 전역 선언
// }