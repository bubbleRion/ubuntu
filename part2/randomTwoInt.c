// 두 난수를 발생 시켜서 비교하기
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_RANDOM 5
int main(void)
{
    int a, b;
    double rand1, rand2;
    static const int a = 1;
    int i = 0;
    while (true)
    {
        i++;
        srand((unsigned int)time(NULL) + i);
        rand1 = rand() / (double)RAND_MAX * MAX_RANDOM;
        srand((unsigned int)time(NULL) + 2);
        rand2 = rand() / (double)RAND_MAX * MAX_RANDOM;
        a = rand1;
        b = rand2;
        // printf("0 ~ 100 사이의 랜덤한 숫자1 : %f", rand1);
        // printf("0 ~ 100 사이의 랜덤한 숫자2 : %f", rand2);
        printf("숫자1 : %d 와 숫자2 : %d \n%s\n", a, b,
               a < b    ? "숫자2가 더 큽니다."
               : a == b ? "두 숫자의 크기가 같습니다."
                        : "숫자1이 더 큽니다.");
        if (a == b)
        {
            break;
        }
    }
    return 0;
}