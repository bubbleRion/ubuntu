#include <stdio.h>

int main()
{
    // 이중포인터
    int var = 10;
    int *pVar1;
    int **pVar2;
    pVar1 = &var;
    pVar2 = &pVar1;
    printf("%d\n", **pVar2);
    // endian
    int a = 0x12345678;
    char *pA;
    pA = (char *)&a;
    printf("0x%x\n", *pA);
    return 1;
}