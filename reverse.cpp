#include "reverse.h"

unsigned long int reverse(unsigned long int num)
{
    unsigned long int res = 0;
    do
    {
        unsigned long int digit = num % 10;
        num /= 10;
        res = res * 10 + digit;
    } while (num > 0);
    return res;
}