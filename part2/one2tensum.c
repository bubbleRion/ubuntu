#include <stdio.h>

int main(void){
    int sum = 0;
    
    for(int i = 100; i <= 10000; ++i){
        sum += i;
    }
    printf("100부터 10000까지 더한 숫자는 %d 입니다. %d\n" , sum , (10000 + 100) * (10000 - 100 + 1) /2);
    return 0;
}