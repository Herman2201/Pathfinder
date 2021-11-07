#include "pathfinder.h"
#include "../libmx/inc/libmx.h"
char **delDuplicate(char **mass)
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
    int size = c3;
    char **massIsl = malloc((size) * sizeof(char **));

    for (int m = 0; m < size; m++)
    {
        for (int i = m + 1; i < size; i++)
        {
            if (!mx_strcmp(names[m], names[i]))
            {
                for (int k = i; k < size - 1; k++)
                {
                    names[k] = names[k + 1];
                }
                size--;
            }
        }
    }
    for (int j = 0; j < size; j++)
    {
        massIsl[j] = names[j];
    }
    mx_del_strarr(&cur_names);
    mx_del_strarr(&cur_parts);
    mx_strdel(names);
    return massIsl;
}

void logic(char **mass)
{
    char **islands = delDuplicate(mass);
    mx_print_strarr(islands, " ");
    int countIsland = 5;
    //int countIsland = mx_atoi(mass[0]);
    int matrix[5][5] = {
        {0, 11, 10, 1000000, 1000000},
        {11, 0, 1000000, 5, 1000000},
        {10, 1000000, 0, 6, 15},
        {1000000, 5, 6, 0, 4},
        {1000000, 1000000, 15, 4, 0},
    };
    int chechMatrix[5][5] = {
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
    };
    // это мы делали пока статическую проверить правильно ли оно все выводит
    //теперь надо сделать динамическую

    int y = 0;
    char ***path = malloc((countIsland * countIsland) * sizeof(char ***)); // плохо  с памятью
    for (int k = 0; k < countIsland; ++k)
    {
        for (int g = 0; g < countIsland; ++g)
        {
            for (int p = 0; p < countIsland; ++p)
            {
                if (g == p || g == k || p == k)
                    continue;
                if ((matrix[g][p] > matrix[g][k] + matrix[k][p]) || (matrix[g][p] == matrix[g][k] + matrix[k][p]))
                {
                    matrix[g][p] = matrix[g][k] + matrix[k][p];
                    if (chechMatrix[g][p] == 0)
                    {
                        chechMatrix[g][p] = 2;
                    }
                    if (y == 0)
                    {
                        path[y] = malloc(4 * sizeof(char **));
                        path[y][0] = islands[g];
                        path[y][1] = islands[k];
                        path[y][2] = islands[p];
                        path[y][3] = NULL;
                        y++;
                    }
                    else
                    {
                        int flag = 1;
                        for (int i = 0; i < y; i++)
                        {
                            // a = mx_strcmp(path[i][0], islands[g]);
                            // mx_printint(a);
                            if (mx_strcmp(path[i][0], islands[p]) == 0 && mx_strcmp(path[i][2], islands[g]) == 0)
                            {
                                // mx_printstr(path[i][0]);
                                // mx_printint(i);
                                // mx_printchar('\n');
                                flag = 0;
                                break;
                            }
                            else
                                flag = 1;
                        }
                        if (flag == 1)
                        {
                            path[y] = malloc(4 * sizeof(char **));
                            path[y][0] = islands[g];
                            path[y][1] = islands[k];
                            path[y][2] = islands[p];
                            path[y][3] = NULL;
                        }
                        y++;
                    }
                }
                //mx_printchar('\n');
            }
        }
    }

    mx_printstr("========================================\n");
    for (int i = 0; i < 19; ++i)
        mx_print_strarr(path[i], " ");
    mx_printstr("========================================\n");
    for (int k = 0; k < countIsland; ++k)
    {
        for (int g = 0; g < countIsland; ++g)
        {
            if (matrix[k][g] == 0 || k == countIsland - 1 || k > g)
                continue;

            mx_printstr("========================================\n");
            mx_printstr("Path: ");
            mx_printstr(islands[k]);
            mx_printstr(" -> ");
            mx_printstr(islands[g]);
            mx_printchar('\n');
            if (chechMatrix[k][g] == 1 || chechMatrix[k][g] == 2)
            {
                // mx_printstr("Route: ");
                // mx_printstr(islands[k]);
                // mx_printstr(" -> ");
                // mx_printstr(islands[g]);
                // mx_printstr(" -> ");
                // mx_printstr("   ");
                // mx_printchar('\n');
                // mx_printstr("Distance: ");
                // mx_printint(matrix[k][g]);
                mx_printstr("Route is calculating...");
                mx_printchar('\n');
                mx_printstr("Distance is calculating...");
            }
            else
            {
                mx_printstr("Route: ");
                mx_printstr(islands[k]);
                mx_printstr(" -> ");
                mx_printstr(islands[g]);
                mx_printchar('\n');
                mx_printstr("Distance: ");
                mx_printint(matrix[k][g]);
            }
            mx_printchar('\n');
            mx_printstr("========================================\n");
        }
    }

    for (int k = 0; k < countIsland; ++k)
    {
        for (int g = 0; g < countIsland; ++g)
        {
            mx_printint(matrix[k][g]);
            mx_printchar(' ');
        }
        mx_printchar('\n');
    }
}

// char **delDuplicate(char **mass)
// {
//     char **cur_parts;
//     char **cur_names;
//     int count = 0;
//     int c3 = 0;
//     for (int i = 1; mass[i] != NULL; i++)
//         count++;
//     char **names = malloc((count + 2) * sizeof(char **));
//     for (int i = 1, k = 0; i < count + 1; i++)
//     {
//         cur_parts = mx_strsplit(mass[i], ',');      // two parts - { "A-B", "2" };
//         cur_names = mx_strsplit(cur_parts[0], '-'); // parts[0] - "A-B" res - two names {"A", "B"}
//         for (int j = 0; j < 2 && k <= count * 2; j++)
//         {
//             names[k] = mx_strdup(cur_names[j]);
//             k++;
//             c3++;
//         }
//     }
//     int size = c3;
//     char **massIsl = malloc((size) * sizeof(char **));

//     for (int m = 0; m < size; m++)
//     {
//         for (int i = m + 1; i < size; i++)
//         {
//             if (!mx_strcmp(names[m], names[i]))
//             {
//                 for (int k = i; k < size - 1; k++)
//                 {
//                     names[k] = names[k + 1];
//                 }
//                 size--;
//             }
//         }
//     }
//     for (int j = 0; j < size; j++)
//     {
//         massIsl[j] = names[j];
//     }
//     mx_del_strarr(&cur_names);
//     mx_del_strarr(&cur_parts);
//     mx_strdel(names);
//     return massIsl;
// }
// char *line(char *s1, char *s2, char s3)
// {
//     int s1_size = mx_strlen(s1);
//     int s2_size = mx_strlen(s2);
//     int size = s1_size + s2_size + 1;

//     char *line = mx_strnew(size);

// }

// int **matrixPath(char **mass)
// {
//     // char **cur_parts;
//     // char **cur_names;
//     //char *a;
//     //int count = 0;
//     char **massIsl = delDuplicate(mass);
//     mx_printstr(massIsl[1]);
//     mx_printchar('\n');
//     mx_print_strarr(massIsl, " ");

//     int countM = mx_atoi(mass[0]);
//     //mx_printint(countM);
//     //int massMatriks[countM][countM];
//     // cur_parts = mx_strsplit(mass[i], ',');      // two parts - { "A-B", "2" };
//     // cur_names = mx_strsplit(cur_parts[0], '-'); // parts[0] - "A-B" res - two names {"A", "B"}

//     for (int i = 0; i < countM; i++)
//     {

//         // for (int j = 0; j < countM; j++)
//         // {
//         mx_printstr(massIsl[1]);
//         mx_printchar('\n');
//         //char *a = mx_strcat(mx_strcat(a, mx_strcat(massIsl[i]), "-"), massIsl[1]);
//         char *a = massIsl[i];
//         mx_strcat(a, "-");
//         mx_strcat(a, massIsl[0]);
//         mx_printstr(a);
//         mx_printchar('\n');

//         mx_printchar('\n');

//         // char *a = mx_strcat(massIsl[i], "-");
//         // a = mx_strcat(a, massIsl[j]);

//         // mx_strcat(a, "-");
//         // mx_strcat(a, massIsl[j]);

//         // mx_printstr(massIsl[i]);
//         // mx_printchar('\n');

//         // massMatriks[i][j] = 1;
//         // massMatriks[i][i] = 0;
//         // }
//     }

//     // for (int i = 0; i < countM; i++)
//     // {
//     //     for (int j = 0; j < countM; j++)
//     //     {
//     //         mx_printint(massMatriks[i][j]);
//     //     }
//     //     write(1, "\n", 1);
//     // }
//     return 0;
// }

// void logic(char **mass)
// {

//     write(1, "\n", 1);
//     //char **mass1 = delDuplicate(mass);
//     matrixPath(mass);
//     // mx_print_strarr(mass1, " ");
//     // write(1, "\n", 1);
//     // write(1, "\n", 1);
//     // mx_print_strarr(mass1, " ");
// }
