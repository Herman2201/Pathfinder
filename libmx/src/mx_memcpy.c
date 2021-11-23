#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    char *dst1 = (char *)dst;
    char *src1 = (char *)src;
    unsigned long i = 0;

    if (n <= 0)
    {
        return dst;
    }
    for (; src1[i] != '\0' && i < n; i += 1)
    {
        dst1[i] = src1[i];
    }
    return dst;
}
