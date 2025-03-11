#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    struct Info
    {
        char name[20];
        int age;
    };
    struct Cake
    {
        char favoriteFood[30];
    };
    struct myData
    {
        struct Info info;
        struct Cake cake;
    };
    struct myData data;
    data.info.age = "29";
}