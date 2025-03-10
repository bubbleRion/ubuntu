#include <stdio.h>
int main(void)
{
    int matrix[3][4] = {{1, 2, 3, 4}, {11, 12, 13, 14}, {21, 22, 3, 24}};
    int sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            sum += matrix[i][j];
        }
    }
    printf("배열의 숫자의 합은 : %d입니다.\n", sum);
}
