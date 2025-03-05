#include <stdio.h>
int main(){
    int a , b;

    a = 5;
    b = ++a;
    printf("a :%d , \t b: %d\n" , a  ,b);

    a = 5;
    b = a++;
    printf("a :%d , \t b: %d" , a  , b);
    return 1;
}
