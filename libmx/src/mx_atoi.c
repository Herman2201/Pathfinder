#include "../inc/libmx.h"

int mx_atoi(const char *str)
{
  int go = -1;
  int goe = -1;
  int dir = 0;
  int dit = 0;

  for (int i = 0; str[i] != '\0'; i++)
  {
    if ((str[i] == '-') && (mx_isdigit(str[i + 1]) == true))
    {
      dir = 1;
    }
    else if ((mx_isspace(str[i]) == false) && (go == -1))
    {
      go = i;
    }
    if ((go > -1) && (mx_isdigit(str[i]) == false) && (goe == -1))
    {
      goe = i;
    }
  }
  if (goe == -1)
  {
    for (int i = go; str[i] != '\0'; i++)
    {
      dit = 10 * dit + (int)str[i] - 48;
    }
  }
  else
  {
    for (int i = go; i < goe; i++)
    {
      dit = 10 * dit + (int)str[i] - 48;
    }
  }
  if (dir == 0)
  {
    return dit;
  }
  else
  {
    return -1 * dit;
  }
}
