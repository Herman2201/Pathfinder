#include "../inc/pathfinder.h"

void mx_parse_structure(int ***array, const size_t s, char **islands_txt, const most **islands)
{
    for (int i = 0; islands_txt[i]; i++)
    {
        char *first = mx_strndup(islands_txt[i], mx_get_char_index(islands_txt[i], '-'));
        islands_txt[i] += mx_get_char_index(islands_txt[i], '-') + 1;
        char *second = mx_strndup(islands_txt[i], mx_get_char_index(islands_txt[i], ','));
        islands_txt[i] += mx_get_char_index(islands_txt[i], ',') + 1;
        int w = mx_atoi(islands_txt[i]);
        int r = 0;
        int c = 0;
        int r_check = 0;
        int c_check = 0;
        for (size_t j = 0; j < s; j++)
        {
            if (mx_strcmp(first, islands[j]->names) == 0 && !r_check)
            {
                r_check = 1;
                r = islands[j]->ind;
            }
            else if (mx_strcmp(second, islands[j]->names) == 0 && !c_check)
            {
                c = islands[j]->ind;
                c_check = 1;
            }

            if (r_check && c_check)
                break;
        }
        (*array)[r][c] = w;
        (*array)[c][r] = w;
    }
}
