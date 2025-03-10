// 10개의 랜덤한 0 ~ 100 배열을 만들고 가장 높은 값을 프린트 하세요.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int arr[45];
    int myNum[6];
    int countSuccess = 0;
    int tryCount = 0;
    long int one = 129402930;
    long int three = 1704390;
    int startTime = (unsigned int)time(NULL);
    int timeIsTickit = (unsigned int)time(NULL);
    while (countSuccess < 4)
    {
        if (startTime != (unsigned int)time(NULL))
        {
            startTime = (unsigned int)time(NULL);
            countSuccess = 0;
            // 내 숫자 생성
            for (int i = 0; i < 6; ++i)
            {
                srand((unsigned int)time(NULL) + i);
                myNum[i] = (rand() / (double)RAND_MAX * 44) + 1;

                printf("내숫자%d : %d ", i + 1, myNum[i]);
            }
            // 로또번호 생성
            printf("\n이번주 로또 번호는~ : ");
            for (int i = 0; i < 6; ++i)
            {
                srand((unsigned int)time(NULL) * 44 + i);
                arr[i] = (rand() / (double)RAND_MAX * 44);
                printf("%d ", arr[i]);
            }

            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; ++j)
                {
                    if (myNum[i] == arr[j])
                    {
                        countSuccess++;
                    }
                }
            }
            printf("\n%d개 맞췄습니다!\n", countSuccess);
            switch (countSuccess)
            {
            case 1:
                printf("다음에는 꼭!\n");
                break;
            case 2:
                printf("다음에는 꼭!\n");
                break;
            case 3:
                printf("5등 당첨~~ 5000원!\n");
                break;
            case 4:
                printf("4등 당첨~~ 50000원!\n");
                break;
            case 5:
                printf("3등 당첨~~ %ld원!\n", three);
                break;
            case 6:
                printf("1등 당첨~~ %ld원!\n", one);
                break;
            default:
                break;
            }
            tryCount++;
        }
    }
    printf("횟수 : %d 투자비용 : %d \n", tryCount, tryCount * 1000);
    printf("%d 초가 걸림.", (unsigned int)time(NULL) - timeIsTickit);
    return 0;
}