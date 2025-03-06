#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int num;
    printf("숫자를 넣으세요: ");
    scanf("%d" , &num);
    if(num < 0)
    {
        num = num; 
    }
    printf("주어진 숫자는 %d 이다.\n" , num);
    printf("주어진 숫자의 16진수 표현은 %x 이다.\n" , num);
    printf("주어진 숫자의 8진수 표현은 %o 이다.\n" , num);
    printf("주어진 숫자의 2진수 표현은 %d 이다.\n" , num);
    return 0;
}