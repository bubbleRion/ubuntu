#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int arr[20] = {0};
    int temp = 0;
    for (int i = 0; i < 20; ++i)
    {
        srand((unsigned int)time(NULL) + i);

        arr[i] = (rand() / (double)RAND_MAX * 99) + 1;
        printf("%d  ", arr[i]);
    }

    for (int i = 20 - 1; i >= 1; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n");

    for (int i = 0; i < 20; ++i)
    {
        printf("%d  ", arr[i]);
    }
}