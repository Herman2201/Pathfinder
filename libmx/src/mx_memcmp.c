#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n)
{
    char *s1_1 = (char *)s1;
    char *s2_2 = (char *)s2;
    unsigned int i = 0;
    for (; s1_1[i] != '\0' && s2_2[i] != '\0' && s1_1[i] == s2_2[i] && i < n - 1; i += 1);
    return s1_1[i] - s2_2[i];
}
