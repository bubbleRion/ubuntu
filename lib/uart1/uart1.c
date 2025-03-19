#include <avr/io.h>

void uart1Init(void){
    UCSR0A |= _BV(U2X1);
    UCSR0B = 0x18; // 0b00011000 Rx, Tx enable
    UCSR0C |= 0x06; // 0b00010110  비동기, no Parity, 1 stop bit

    UBRR0H = 0x00;
    UBRR0L = 0x07; // 115200 bps
}
void uart1Transmit(char data){

}
unsigned char uart1Receive(void){
    while ((UCSR0A & 0x80) == 0) // 문자 버퍼에 있으면 루프 탈출
        ;
    return UDR0;
}
void uart1PrintStirng(char *str){
    
}
void uart1PrintStirng(unsigned char n){

}
