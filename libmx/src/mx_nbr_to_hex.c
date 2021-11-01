#include "../inc/libmx.h"

static int len(unsigned long num)
{
    int k = 0;
    while (num)
    {
        num /= 16;
        k += 1;
    }
    return k;
}

char *mx_nbr_to_hex(unsigned long nbr)
{
    int k, q = 0;

    unsigned long num = nbr;
    char *aboba = NULL;
    k = len(nbr);
    aboba = mx_strnew(k);
    while (num)
    {
        q = num % 16;
        if (q < 10)
        {
            aboba[--k] = 48 + q;
        }
        if (q > 10)
        {
            aboba[--k] = 87 + q;
        }
        num /= 16;
    }
    return aboba;
}
