#include "../inc/libmx.h"

char *mx_strtrim(const char *str)
{
    if (!str)
    {
        return NULL;
    }
    while (mx_isspace(*str))
    {
        str += 1;
    }

    int len = mx_strlen(str);

    while (mx_isspace(str[len - 1]))
    {
        len -= 1;
    }
    return mx_strndup(str, len);
}
