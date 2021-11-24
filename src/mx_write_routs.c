#include "../inc/pathfinder.h"

void mx_write_routs(int **init, int **w_arr, parse *h, int isl_c, const most **island)
{
    int e = h->r[h->p];
    int s = h->r[0];
    for (int k = 0; k < isl_c; k++)
    {
        if (k != h->r[h->p] && (init[e][k] == w_arr[e][s] - w_arr[k][s]))
        {
            h->p++;
            h->r[h->p] = k;
            mx_write_routs(init, w_arr, h, isl_c, island);
            h->p--;
        }
    }

    if (h->r[h->p] != s)
        return;

    int distance = 0;

    for (int i = 0; i < 40; i++)
    {
        mx_printchar('=');
    }
    mx_printstr("\nPath: ");
    mx_printstr(island[h->r[1]]->names);
    mx_printstr(" -> ");
    mx_printstr(island[h->r[0]]->names);
    mx_printchar('\n');
    mx_printstr("Route: ");
    for (int i = 1; i < h->p + 1; i++)
    {
        mx_printstr(island[h->r[i]]->names);
        if (i < h->p)
        {
            mx_printstr(" -> ");
        }
    }

    mx_printstr("\nDistance: ");
    for (int i = 1; i < h->p; i++)
    {
        int temp = init[h->r[i]][h->r[i + 1]];
        mx_printint(temp);
        distance += temp;
        if (i < h->p - 1)
        {
            mx_printstr(" + ");
        }
    }

    if (h->p != 2)
    {
        mx_printstr(" = ");
        mx_printint(distance);
    }
    mx_printchar('\n');
    for (int i = 0; i < 40; i++)
    {
        mx_printchar('=');
    }
    mx_printchar('\n');
}
