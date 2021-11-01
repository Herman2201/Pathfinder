#include "../inc/libmx.h"

char *mx_strnew(const int size)
{
  char *froze;
  if (size < 0)
  {
    return NULL;
  }
  froze = (char *)malloc(sizeof(char) * size + 1);
  for (int k = 0; k <= size; k += 1)
  {
    froze[k] = '\0';
  }
  return froze;
}
