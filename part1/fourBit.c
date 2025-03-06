#include <stdio.h>
#define BOLD 0x01
// #define ITALIC 0x02
#define ITALIC (0x01 << 1)
#define SHADOW (0x01 << 2)
#define UL (0x01 << 3)

void printAttrib(unsigned char attr);
void printAttrib2(unsigned char attr);
int main(void){
    unsigned char attr;
    unsigned char attr2;

    attr ^= attr;
    attr |= BOLD;
    printAttrib(attr);
    printAttrib2(attr);
    attr |= (BOLD | SHADOW);
    printAttrib(attr);
    printAttrib2(attr);
    attr &= (~BOLD);
    printAttrib(attr);
    printAttrib2(attr);
    // attr2 = (~BOLD);
    // printf("attr: 0x%02x\n" , attr2);
    return 1;
}

void printAttrib(unsigned char attr){
    // printf("attr: 0x%02x\n" , attr);
    printf("BOLD : 0x%02x\n" , !(~(attr | ~BOLD)));
    printf("ITALIC : 0x%02x\n" , !(~(attr | ~ITALIC)>>1));
    printf("SHADOW : 0x%02x\n" , !(~(attr | ~SHADOW)>>2));
    printf("UL : 0x%02x\n" , !(~(attr | ~UL)>>3));
    printf("--------------------------------\n");
    
}

void printAttrib2(unsigned char attr){
    printf("attr : 0x%02x\n" , attr);
    printf("BOLD : 0x%02x\n" , attr & BOLD);
    printf("ITALIC : 0x%02x\n" , (attr & ITALIC) >> 1);
    printf("SHADOW : 0x%02x\n" , (attr & SHADOW) >> 2);
    printf("UL : 0x%02x\n" , (attr & SHADOW) >> 3);
    printf("--------------------------------\n");
}

