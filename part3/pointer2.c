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
    return 1;
}