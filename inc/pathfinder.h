#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "libmx.h"

#define INF 9999999

typedef struct s_most {
    char *names;
    int ind;
} most;

typedef struct s_parse {
    int *r;
    int p;
} parse;


most **mx_err(const char *fname);
void mx_parse_structure(int ***array, const size_t s, char **isl_t, const most** island);
void mx_write_routs( int **init, int **w_arr, parse *h, int islands_count, const most **island);
void mx_clean(most ***island);
#endif
