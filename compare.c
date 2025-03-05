#include <stdio.h>

int main(void){
    int a, b;
    int greater;
    printf("두 정수를 입력하세요 : ");
    scanf("%d , %d" , a , b);

    greater = a > b;
    printf("greater의 값은 %d이다." , greater);
    return 0;
}