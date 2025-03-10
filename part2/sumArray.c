#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int num[10];
    int sum = 0;
    srand(time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        num[i] = rand() / (double)RAND_MAX * 100;
        sum += num[i];
        printf("난수%d: %d\n ", i + 1, num[i]);
    }
    printf("%d \n", sum);

    return 0;
}