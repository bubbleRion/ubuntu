#include <stdio.h>
void hello();

int main(){
    int a;
    int len_a = sizeof(a);
    // printf("%d , %d\n" , a , len_a);
    int b = 39;
    a = 111;

    printf("a = %d\n b = %d\n" , ~a , b);

}

void hello(){
    printf("hello , my friend\n");
    
}