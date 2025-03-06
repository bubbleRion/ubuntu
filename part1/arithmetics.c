#include <stdio.h>
int main(){
    int a , b;
    printf("Input a , b :");
    scanf("%d %d", &a , &b);
    printf("PLUS %d + %d = %d\n" , a , b , a + b);
    printf("MINUS %d - %d = %d\n" , a , b , a - b);
    printf("DIVISION %d * %d = %d\n" , a , b , a * b);
    printf(" %d / %d = %d\n" , a , b , a / b);
    printf("%d 나누기 %d 의 나머지 = %d\n" , a , b , a % b);
    return 1;
}
