#include "../inc/libmx.h"
void mx_del_strarr(char ***arr)
{
    for (int i = 0; (*arr)[i] != NULL; i += 1)
    {
        mx_strdel(&(*arr)[i]);
    }
    free(*arr);
    *arr = NULL;
}
