#include "myRandom.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    my_srand(time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        int num = my_rand();
        printf("%d ,", num);
    }
    printf("\n");
    return 0;
}