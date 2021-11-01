#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len)
{
	char *dst1 = (char *)dst;
	char *src1 = (char *)src;

	char *temp = mx_strnew(len);
	for (unsigned int i = 0; i < len; i += 1)
	{
		temp[i] = src1[i];
	}
	for (unsigned int i = 0; i < len; i += 1)
	{
		dst1[i] = temp[i];
	}
	free(temp);
	return dst1;
}
