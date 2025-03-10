#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int mynum[3] = {0};
    int randomNum[3] = {0};
    int notSuccess = 1;
    int tryCount = 1;

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &mynum[i]);
    }

    while (notSuccess)
    {
        printf("\n");
        int strike = 0;
        int ball = 0;
        printf("랜덤한 숫자 3개 :");
        for (int i = 0; i < 3; i++)
        {
            if (randomNum[i] == randomNum[2 - i])
            {
                randomNum[i] = (rand() / (double)RAND_MAX * 9);
                printf("%d ", randomNum[i]);
            }
            else
            {
            }
        }
        printf("\n %d번째 시도==>", tryCount);
        for (int i = 0; i < 3; i++)
        {

            for (int j = 0; j < 3; ++j)
            {
                if (mynum[i] == randomNum[j] && i == j)
                {
                    strike++;
                }

                if (mynum[i] == randomNum[j] && i != j)
                {
                    ball++;
                }
            }
        }

        printf("\n스트라이크 갯수 : %d , 볼 갯수 : %d", strike, ball);

        if (strike >= 3)
        {
            notSuccess--;
            printf("\n입력값 : %d , %d , %d : %d 회만에 성공!\n", mynum[0], mynum[1], mynum[2], tryCount);
        }
        else
        {
            tryCount++;
        }
    }
    return 1;
}