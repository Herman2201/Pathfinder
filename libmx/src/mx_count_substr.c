#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub)
{
    if (str == NULL || sub == NULL)
    {
        return -1;
    }
    int counter = 0;
    while ((str = mx_strstr(str, sub)) != 0)
    {
        str += mx_strlen(sub);
        counter += 1;
    }
    return counter;
}
