#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len)
{
	int i = 0;
	for (; i < len && src[i] != '\0'; i += 1)
	{
		dst[i] = src[i];
	}
	while (i < len)
	{
		dst[i] = '\0';
		i += 1;
	}
	return dst;
}
