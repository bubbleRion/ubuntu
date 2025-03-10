#include <stdio.h>

char *upper(char *inputString)
{

    for (int i = 0; inputString[i] != 0; ++i)
    {
        if (96 < inputString[i] && 123 > inputString[i])
        {
            inputString[i] -= 32;
        }
    }
    return inputString;
}

char *lower(char *inputString)
{

    for (int i = 0; inputString[i] != 0; ++i)
    {
        if (64 < inputString[i] && 91 > inputString[i])
        {
            inputString[i] += 32;
        }
    }
    return inputString;
}

void executer(char *(*fp)(char *))
{
    char s1[100] = {0};
    scanf("%s", s1);
    printf("%s\n", fp(s1));
}

int main()
{
    executer(upper);
    executer(lower);
}