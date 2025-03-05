#include <stdio.h>
void hello();

int main(){
    int a;
    int len_a = sizeof(a);
    printf("%d , %d\n" , a , len_a);
    

}

void hello(){
    printf("hello , my friend\n");
    
}