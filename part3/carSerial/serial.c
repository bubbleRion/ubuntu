#include "serial.h"

int getSerialNumber(void)
{
    static int count = 0;
    int result = count;
    ++count;
    return result;
    // return count++;
}