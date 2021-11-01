#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex)
{
	int length = 0;
	unsigned long number = 0;
	unsigned long found = 1;
	if (hex != NULL)
	{
		while (hex[length])
		{
			length += 1;
		}
	}
	else
	{
		return 0;
	}
	for (int i = 0; i <= length; i++)
	{
		if (hex[length - i] >= '0' && hex[length - i] <= '9')
		{
			number += (hex[length - i] - 48) * found;
			found *= 16;
		}
		if (hex[length - i] >= 'A' && hex[length - i] <= 'F')
		{
			number += (hex[length - i] - 55) * found;
			found *= 16;
		}
		if (hex[length - i] >= 'a' && hex[length - i] <= 'f')
		{
			number += (hex[length - i] - 87) * found;
			found *= 16;
		}
	}
	return number;
}
