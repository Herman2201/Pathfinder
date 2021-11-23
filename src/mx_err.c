#include "../inc/pathfinder.h"
int mx_error_line(const char *f)
{
    while (*f != '\n')
    {
        if (!mx_isdigit(*f))
        {
            return 1;
        }
        f++;
    }

    return 0;
}
int mx_num_check(const char *f)
{
    while (*f)
    {
        if (!mx_isdigit(*f))
        {
            return 1;
        }
        f++;
    }

    return 0;
}

int mx_check_island(most ***island, int *ins_ind, const char *isl)
{
    int ex = 0;
    for (int i = 0; i < *ins_ind; i++)
    {
        if (mx_strcmp((*island)[i]->names, isl) == 0)
        {
            ex = 1;
            break;
        }
    }
    if (!ex)
    {
        (*island)[*ins_ind]->names = (char *)isl;
        (*island)[*ins_ind]->ind = *ins_ind;
        *ins_ind += 1;
    }

    return ex;
}

int mx_inv_line(const char *l, most ***island, int *ins_ind)
{
    int inv = 0;
    int del_ind = mx_get_char_index(l, '-');
    int del_ind_com = 0;
    if (del_ind < 0)
    {
        return 1;
    }

    char *f_dist = mx_strndup(l, del_ind);
    if (f_dist == NULL)
    {
        inv = 1;
    }

    l += (del_ind + 1);
    del_ind_com = mx_get_char_index(l, ',');
    if (del_ind_com < 0)
    {
        inv = 1;
    }
    char *s_dist = mx_strndup(l, del_ind_com);

    if (s_dist == NULL)
    {
        inv = 1;
    }
    if (mx_strlen(f_dist) == 0 || mx_strlen(s_dist) == 0)
    {
        inv = 1;
    }
    if (mx_strcmp(f_dist, s_dist) == 0)
    {
        inv = 1;
    }
    l += (del_ind_com + 1);
    if (mx_num_check((const char *)l))
    {
        inv = 1;
    }
    for (int i = 0; i < mx_strlen(f_dist); i++)
    {
        if (!mx_isalpha(f_dist[i]))
        {
            inv = 1;
            break;
        }
    }
    for (int i = 0; i < mx_strlen(s_dist); i++)
    {
        if (!mx_isalpha(s_dist[i]))
        {
            inv = 1;
            break;
        }
    }
    if (f_dist != NULL || mx_strlen(f_dist) != 0)
    {

        if (mx_check_island(island, ins_ind, f_dist))
        {
            free(f_dist);
        }
    }
    if (s_dist != NULL || mx_strlen(s_dist) != 0)
    {
        if (mx_check_island(island, ins_ind, s_dist))
        {
            free(s_dist);
        }
    }

    return inv;
}

int mx_inv_l(const char *f, most ***island)
{
    char **l = mx_strsplit(f, '\n');
    int island_count = mx_atoi(l[0]);
    int ins_ind = 0;
    int inv_line = 0;
    (*island) = (most **)malloc(sizeof(most *) * (island_count + 1));
    for (int i = 0; i < island_count + 1; i++)
    {
        (*island)[i] = (most *)malloc(sizeof(most));
    }

    for (int i = 1; l[i]; i++)
    {
        int index_hyphen = mx_get_char_index(l[i], '-');
        int index_comma = mx_get_char_index(l[i], ',');
        if (index_comma < index_hyphen)
        {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            mx_del_strarr(&l);
            inv_line = 1;
            break;
        }

        else if (mx_inv_line(l[i], island, &ins_ind))
        {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            mx_del_strarr(&l);
            inv_line = 1;
            break;
        }
    }
    if (l)
    {
        mx_del_strarr(&l);
    }
    if (!inv_line)
    {
        (*island)[ins_ind] = NULL;
    }
    if (island_count != ins_ind || inv_line)
    {
        (*island)[island_count] = NULL;
        if (!inv_line)
        {
            mx_printerr("error: invalid number of island\n");
        }
        return 1;
    }
    return 0;
}

int mx_duplicate(char *f)
{
    char **l = mx_strsplit(f, '\n');
    char **cur_parts;
    char **cur_names;
    char **parts;
    char **names;
    int inv = 0;

    for (int i = 1; l[i] != NULL; i++)
    {
        cur_parts = mx_strsplit(l[i], ',');
        cur_names = mx_strsplit(cur_parts[0], '-'); 
        for (int j = 1; j < i; j++)
        {
            parts = mx_strsplit(l[j], ',');
            names = mx_strsplit(parts[0], '-');
            if ((mx_strcmp(names[0], cur_names[0]) == 0 &&
             mx_strcmp(names[1], cur_names[1]) == 0) || (mx_strcmp(names[1], cur_names[0]) == 0 && mx_strcmp(names[0], cur_names[1]) == 0))
            {
               inv = 1;
            }

            mx_del_strarr(&parts);
            mx_del_strarr(&names);
        }
        mx_del_strarr(&cur_names);
        mx_del_strarr(&cur_parts);
    }
    mx_del_strarr(&l);
    return inv;
}

//--

int mx_big_bridg(char *f)
{
    int inv = 0;
    char **c_pat;
    int summary = 0;
    char **l = mx_strsplit(f, '\n');

    for (int i = 1; l[i] != NULL; i++)
    {
        c_pat = mx_strsplit(l[i], ',');
        summary += mx_atoi(c_pat[1]);
        if ((mx_strlen(c_pat[1]) > 9 && c_pat[1][0] >= '3') || mx_atoi(c_pat[1]) < 0 || summary > 2147483647 || summary < 0)
        {
            inv = 1;
            break;
        }
    }

    mx_del_strarr(&l);
    return inv;
}

most **mx_err(const char *fnames)
{
    int op_f = open(fnames, O_RDONLY);
    int h_err = 0;
    most **island = NULL;
    char *f = 0;
    if (op_f < 0)
    {
        mx_printerr("error: file ");
        mx_printerr(fnames);
        mx_printerr(" does not exist\n");
        h_err = 1;
    }
    else if (mx_strlen((f = mx_file_to_str(fnames))) == 0)
    {
        mx_printerr("error: file ");
        mx_printerr(fnames);
        mx_printerr(" is empty\n");
        h_err = 1;
    }
    else if (mx_error_line(f))
    {
        mx_printerr("error: line 1 is not valid\n");
        h_err = 1;
    }
    else if (mx_inv_l(f, &island) > 0)
    {
        h_err = 1;
    }
    else if (mx_duplicate(f))
    {
        mx_printerr("error: duplicate bridges\n");
        h_err = 1;
    }
    else if (mx_big_bridg(f))
    {
        mx_printerr("error: sum of bridges lengths is too big\n");
        h_err = 1;
    }

    close(op_f);
    if (f != NULL)
        free(f);
    if (h_err)
    {
        if (island != NULL)
            mx_clean(&island);
        exit(-1);
    }
    return island;
}
