#include "../inc/libmx.h"

void mx_printint(int n)
{
  if (n == -2147483648)
  {
    write(1, "-2147483648", 11);
    return;
  }
  int num = n;
  if (n < 0)
  {
    num = n * -1;
    mx_printchar('-');
  }
  if (num >= 10)
  {
    mx_printint(num / 10);
  }
  mx_printchar((num % 10) + 48);
}
