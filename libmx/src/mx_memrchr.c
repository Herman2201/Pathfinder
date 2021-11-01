#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n)
{
	char *s1 = (char *)s;
	for (unsigned int i = n - 1; i > 0; i -= 1)
	{
		if (s1[i] == c)
		{
			return s1 + i;
		}
	}
	if (s1[0] == c)
	{
		return s1;
	}
	return NULL;
}
