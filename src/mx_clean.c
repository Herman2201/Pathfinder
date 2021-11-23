#include "../inc/pathfinder.h"

void mx_clean(most ***island)
{

    for (int i = 0; (*island)[i]; i++)
    {
        if ((*island)[i]->names)
            free((*island)[i]->names);
        free((*island)[i]);
    }
}
