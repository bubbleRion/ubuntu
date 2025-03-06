// 임이의 char를 scanf로 하나 받아서 대문자인지 소문자인지 출력하세요.

#include <stdio.h>

int main(void){
    char isUpper;
    scanf("%c" , &isUpper);
    printf("%c , 이 문자는 %s입니다.\n", isUpper ,  isUpper >= 97 ? "소문자" : "대문자");
}