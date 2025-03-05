#include <stdio.h>

int main(void){
    int man , woman;
    double sum , manRate , womanRate;

    //입력 받는 코드
    scanf("%d %d" , &man , &woman);
    //연산 하는 코드
    sum = man + woman;
    manRate = man / sum;
    womanRate = woman / sum;
    printf("남자의 수는 %d명이고 여자의 수는 %d명이다. \n", man , woman);
    printf("총 수는 %.f명\n남자의 비율은 %.2f%%\n 여자의 비율은 %.2f%%\n" , sum , manRate , womanRate);
    return 0;
}