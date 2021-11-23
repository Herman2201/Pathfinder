#include "../inc/pathfinder.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 0;
    }

    most **island = mx_err(argv[1]);
    size_t s = 0;
    for (; island[s]; s++)
        ;

    char *inp = mx_file_to_str(argv[1]);
    while (*inp != '\n')
    {
        inp += 1;
    }
    inp += 1;
    char **isl_t = mx_strsplit(inp, '\n');

    int **arr = (int **)malloc(sizeof(int *) * s);
    for (size_t i = 0; i < s; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * s);
        for (size_t j = 0; j < s; j++)
            arr[i][j] = INF;
    }

    mx_fill_array(&arr, s, isl_t, (const most **)island);

    // создание матрицы кратчайших путей

    int **w_mat = (int **)malloc(sizeof(int *) * s);
    for (size_t i = 0; i < s; i++)
    {
        w_mat[i] = (int *)malloc(sizeof(int) * s);
        for (size_t j = 0; j < s; j++)
        {
            w_mat[i][j] = arr[i][j];
        }
    }

    for (size_t k = 0; k < s; k++)
    {
        for (size_t i = 0; i < s; i++)
        {
            for (size_t j = i + 1; j < s; j++)
            {

                if (w_mat[k][j] != INF && w_mat[i][k] != INF &&
                    w_mat[i][k] + w_mat[k][j] < w_mat[i][j])
                {
                    w_mat[i][j] = w_mat[i][k] + w_mat[k][j];
                    w_mat[j][i] = w_mat[i][k] + w_mat[k][j];
                }
            }
        }
        w_mat[k][k] = 0;
    }
    int **w_arr = w_mat;

    //-----

    // вывод путей
    int s1 = s;

    parse *h = (parse *)malloc(sizeof(parse));
    h->r = (int *)malloc(sizeof(int) * (s1 + 1));
    for (int i = 0; i < s1; i++)
    {
        for (int j = i + 1; j < s1; j++)
        {
            h->p = 1;
            h->r[0] = j;
            h->r[1] = i;
            mx_print_spaths(arr, w_arr, h, s, (const most **)island);
        }
    }
    free(h->r);
    free(h);
    //----

    mx_clean(&island);
    for (size_t i = 0; i < s; i++)
    {
        free(w_arr[i]);
        free(arr[i]);
    }
    free(w_arr);
    free(arr);
    return 0;
}
