#include <stdio.h>

int main()
{
    unsigned int a = 1;

    int num;
    printf("숫자를 넣으세요: ");
    scanf("d", &num);
    if (num < 0)
    {
        num = -num;
    }
    printf("주어진 숫자의 절대값은 %d 이다.", num);
    return 0;
}