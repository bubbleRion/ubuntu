#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int compare(const void *a, const void *b)
{
    return (&a - &b);
}
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

    qsort(arr, 20, sizeof(arr[0]), compare);
    printf("\n");

    for (int i = 0; i < 20; ++i)
    {
        printf("%d  ", arr[i]);
    }
}