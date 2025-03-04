#include <stdio.h>
int main(){
    char ch1 = 'A';
    char ch2 = 65;
    char ch3;
    printf("c = %c , d = %d\n" , ch1 , ch1);
    printf("c = %c , d = %d\n" , ch2 , ch2);
    printf("input A character : \n");
    scanf("%c" , &ch3);
    printf("c = %c , d = %d" , ch3 , ch3);
    return 1;
}
