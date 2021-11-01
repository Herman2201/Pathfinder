#include "../inc/libmx.h"

void mx_pop_back(t_list **list)
{
  if (*list == NULL)
  {
    return;
  }
  t_list *p = *list;
  while (p->next->next)
  {
    p = p->next;
  }
  free(p->next);
  p->next = NULL;
  p = NULL;
}
