// 10개의 랜덤한 0 ~ 100 배열을 만들고 가장 높은 값을 프린트 하세요.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int arr[10];
    int max = arr[0];
    srand(time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        arr[i] = rand() / (double)RAND_MAX * 100;

        printf("숫자%d : %d\n", i + 1, arr[i]);
    }
    for (int j = 0; j < 10; j++)
    {
        if (max < arr[j])
        {
            max = arr[j];
        }
    }
    printf("%d \n", max);

    return 0;
}