#include <stdio.h>

int main(void){
    int sosu = 100;
    int answer = 0;
    for (int i = 2; i <= sosu; i++){
        int count = 0;
        for (int j = 2; j <= i; j++){
            if(i % j == 0){
                count++;
            }
            else{
                continue;
            }
        }
        if(count == 1){
            answer++;
        }
    }
    
    printf("%d 까지 세어보면 소수 숫자의 개수는 : %d 개 입니다." , sosu , answer);
    return 1;
}