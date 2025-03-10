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
        printf("%d\t", arr[i]);
    }
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 20; ++i)
    {
        printf("%d\n", arr[i]);
    }
    return 1;
}