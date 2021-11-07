#include "pathfinder.h"
#include "../libmx/inc/libmx.h"

//функция для валидности первой строки
void oneLine(char **mass)
{
    int j = 0;
    while (mass[0][j])
    {
        if (!mx_isdigit(mass[0][j]))
        {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
        j++;
    }
}

// функция для проверки первой строки на инт и совпадение колличества островов
void oneLineIsl(char **mass)
{

    char **cur_parts;
    char **cur_names;
    int count = 0;
    int c3 = 0;
    for (int i = 1; mass[i] != NULL; i++)
        count++;
    char **names = malloc((count + 2) * sizeof(char **));
    for (int i = 1, k = 0; i < count + 1; i++)
    {
        cur_parts = mx_strsplit(mass[i], ',');      // two parts - { "A-B", "2" };
        cur_names = mx_strsplit(cur_parts[0], '-'); // parts[0] - "A-B" res - two names {"A", "B"}
        for (int j = 0; j < 2 && k <= count * 2; j++)
        {
            names[k] = mx_strdup(cur_names[j]);
            k++;
            c3++;
        }
    }
    //     mx_printint(c3);
    // //  mx_print_strarr(names,"*");
    int count1 = 1;
    int buf = 0;
    for (int k = 1; k < c3; k++)
    {
        buf = 0;
        for (int g = k - 1; g >= 0; g--)
        {
            if (!mx_strcmp(names[k], names[g]))
            {
                buf = 1;
            }
        }
        if (!buf)
            count1++;
    }
    if (mx_atoi(mass[0]) != count1)
    {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
}
//функция для проверки long long
void maxInt(char **mass)
{
    long long sum = 0;
    char **cur_parts;
    for (int i = 1; mass[i] != NULL; i++)
    {
        cur_parts = mx_strsplit(mass[i], ','); // two parts - { "A-B", "2" };
        sum += mx_atoi(cur_parts[1]);
        if ((mx_strlen(cur_parts[1]) > 9 && cur_parts[1][0] >= '3') || mx_atoi(cur_parts[1]) < 0 || sum > 2147483647 || sum < 0)
        {
            mx_printerr("error: sum of bridges lengths is too big \n");
            exit(0);
        }
        // if ((mx_strlen(cur_parts[1]) > 9 && cur_parts[1][0] <= 3) /*|| mx_atoi(cur_parts[1]) < 0*/)
        // {
        //     mx_printerr("error: sum of bridges lengths is too big \n");
        //     exit(0);
        // }
        // mx_del_strarr(&cur_parts);
    }
}
// функция для проверки правильности написания строк
bool errorLine(char *mass)
{
    int index_hyphen = mx_get_char_index(mass, '-');
    int index_comma = mx_get_char_index(mass, ',');
    if (index_comma < index_hyphen)
    {
        return false;
    }
    for (int i = 0; mass[i] != '\0'; i++)
    {
        if (i == index_hyphen)
        {
            continue;
        }
        if (i == index_comma)
        {
            continue;
        }
        if (i > index_comma)
        {
            if (!mx_isdigit(mass[i]))
            {
                return false;
            }
            continue;
        }
        if (!mx_isalpha(mass[i]))
        {
            return false;
        }
    }
    return true;
}
//функия на одинаковые названия остовов в строке
void errorLineIsl(char **mass)
{
    char **cur_parts;
    char **cur_names;
    for (int i = 1; mass[i] != NULL; i++)
    {
        cur_parts = mx_strsplit(mass[i], ',');      // two parts - { "A-B", "2" };
        cur_names = mx_strsplit(cur_parts[0], '-'); // parts[0] - "A-B" res - two names {"A", "B"}
        if (mx_strcmp(cur_names[0], cur_names[1]) == 0)
        {
            mx_printerr("error: line ");
            mx_printint(i + 1);
            mx_printerr(" is not valid\n");
            exit(0);
        }
        mx_del_strarr(&cur_names);
        mx_del_strarr(&cur_parts);
    }
}

// функция на повторы
static void errorDuple(char **mass)
{
    char **cur_parts;
    char **cur_names;
    char **parts;
    char **names;
    for (int i = 1; mass[i] != NULL; i++)
    {
        cur_parts = mx_strsplit(mass[i], ',');      // two parts - { "A-B", "2" };
        cur_names = mx_strsplit(cur_parts[0], '-'); // parts[0] - "A-B" res - two names {"A", "B"}
        for (int j = 1; j < i; j++)
        {
            parts = mx_strsplit(mass[j], ',');
            names = mx_strsplit(parts[0], '-');
            if ((mx_strcmp(names[0], cur_names[0]) == 0 &&
             mx_strcmp(names[1], cur_names[1]) == 0) || (mx_strcmp(names[1], cur_names[0]) == 0 && mx_strcmp(names[0], cur_names[1]) == 0))
            {
                mx_printerr("error: duplicate bridges\n");
                exit(1);
            }

            mx_del_strarr(&parts);
            mx_del_strarr(&names);
        }
        mx_del_strarr(&cur_names);
        mx_del_strarr(&cur_parts);
    }
}

void fileContents(char **mass)
{
    oneLine(mass);

    for (int i = 1; mass[i] != NULL; i++)
    {
        if (errorLine(mass[i]) == false)
        {
            mx_printerr("error: line ");
            mx_printint(i + 1);
            mx_printerr(" is not valid\n");
            exit(0);
        }
    }
    errorLineIsl(mass);
    oneLineIsl(mass);
    errorDuple(mass);

    maxInt(mass);
}
