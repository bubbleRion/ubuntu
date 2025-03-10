// 난수 6개 만들기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_RANDOM 5
int main(void)
{
    int dice[30];
    srand(time(NULL));

    for (int i = 0; i < 30; ++i)
    {
        dice[i] = rand() % 6 + 1;
        printf("%p  ", &dice[i]);
    }
    printf("\n");

    for (int i = 0; i < 30; ++i)
    {
        dice[i] *= 10;
        printf("%p  ", (&dice[i]));
    }
    printf("\n");

    return 0;
}