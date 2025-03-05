#include <stdio.h>
int main(){
    const int a;
    const int b;
    
 
    printf("%d %d %d\n" , 100, 0144, 0x64);
    printf("%d 0%o 0x%x\n" , 100, 0144, 0x64);

    printf("%lldLL\n" , 10000000000LL);

    printf("%f %f\n" , 2.718 , 3.141592F);
    printf("%d %d %d\n" , 'A' , 'a' , 0);
    printf("%c %c %c\n" , 65 , 97 , 48);
    printf("%c %c %c\n" , 'A' , 'A'+1 , 'A'+2);

    printf("%c %c %c\n" , 65 , 97 , 48);
    return 1;
}
