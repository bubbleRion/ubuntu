#ifndef UART1_H_
#define UART1_H_

void uart1Init(void);
void uart1Transmit(char data);
unsigned char uart1Receive(void);
void uart1PrintStirng(char *str);
void uart1PrintStirng(unsigned char n);

#endif