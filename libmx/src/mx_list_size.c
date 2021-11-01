#include "../inc/libmx.h"

int mx_list_size(t_list *list)
{
    if (list == NULL) {
      return 0;
    }
    t_list *p = list;
    int count =0;
    while (p) {
      p = p -> next;
      count += 1;
    }
    return count;
}

