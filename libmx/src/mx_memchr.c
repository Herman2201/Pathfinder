#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n)
{
	char *s1 = (char *)s;
	for (unsigned long i = 0; *s1 != 0 && i < n; s1++ && i++)
	{
		if (*s1 == c)
			return s1;
	}
	return NULL;
}
