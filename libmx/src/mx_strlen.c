#include "../inc/libmx.h"

int mx_strlen(const char *s)
{
  int counter = 0;
  for (int i = 0; s[i] != '\0'; i += 1)
  {
    counter += 1;
  }
  return counter;
}
