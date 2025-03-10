// 10개의 랜덤한 0 ~ 100 배열을 만들고 가장 높은 값을 프린트 하세요.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int arr[10];
    int num;
    int randomIsInNum = 0;
    scanf("%d", &num);
    for (int i = 0; i < 10; ++i)
    {
        arr[i] = rand() / (double)RAND_MAX * 15;

        printf("숫자%d : %d\n", i + 1, arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        if (num == arr[i])
        {
            randomIsInNum = 1;
        }
    }

    printf("입력한 값은 %d인데, 배열안에 %s \n", num, randomIsInNum ? "있소" : "없소");

    return 0;
}