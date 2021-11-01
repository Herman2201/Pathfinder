#include "../inc/libmx.h"

void mx_str_reverse(char *s)
{
    int len = mx_strlen(s);
    for (int i = 0; i < len / 2; i += 1)
    {
        mx_swap_char(&s[i], &s[len - i - 1]);
    }
}
