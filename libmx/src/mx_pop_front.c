#include "../inc/libmx.h"

void mx_pop_front(t_list **list)
{
    t_list *p = NULL;
    if (*list == NULL)
        return;
    if ((*list)->next == NULL)
    {
        free(*list);
        *list = NULL;
    }
    else
    {
        p = (*list)->next;
        free(*list);
        *list = p;
    }
}
