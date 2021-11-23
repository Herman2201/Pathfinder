#include "../inc/libmx.h"

static char *str_fill(const char *file, int size)
{
    int p = open(file, O_RDONLY);
    char *str = mx_strnew(size);

    p = open(file, O_RDONLY);
    read(p, str, size);
    close(p);
    return str;
}

char *mx_file_to_str(const char *file)
{
    int p = open(file, O_RDONLY);
    int size = 0;
    char c;
    char *str = NULL;

    if (p < 0)
    {
        close(p);
        return NULL;
    }
    if (p > 0)
    {
        while (read(p, &c, 1))
        {
            size += 1;
        }
        close(p);
        str = str_fill(file, size);
        return str;
    }
    close(p);
    return NULL;
}
