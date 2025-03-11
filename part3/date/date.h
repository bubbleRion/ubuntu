#pragma once
#include <stdio.h>

typedef struct date
{
    int year;
    int month;
    int day;
} Date;

void printDate(Date *);
