#include <limits.h>
#include <stdio.h>

void printHello();

// int main(int argc, char* argv[]) 인수를 받을 때
int main(void)
{
    printHello();
    printf("char_bit : %d\n", CHAR_BIT);
    printf("char_max : %d\n", CHAR_MAX);
    printf("INT_MIN : %d \t, %d\n", INT_MIN , INT_MAX);
    printf("LONG_MIN : %ld \t, %ld\n", LONG_MIN , LONG_MAX);

    printf("INT_MIN +2 %d\n", INT_MAX  + 2);

    
    return 0;
}

void printHello()
{
    printf("Hello, world!\n");
}