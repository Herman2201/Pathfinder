#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len)
{
	char *stack = (char *)big;
	char *little1 = (char *)little;
	if (big_len > little_len && little_len > 0 && big_len > 0)
	{

		for (; *stack; ++stack)
		{
			if (*stack == *little1)
			{
				if (mx_strncmp(stack, little1, little_len) == 0)
				{
					return (char *)stack;
				}
			}
		}
	}
	return NULL;
}
