#include "../inc/libmx.h"

t_list *mx_create_node(void *data)
{
    t_list *list = (t_list *)malloc(16);
    list->next = NULL;
    list->data = data;
    return list;
}
