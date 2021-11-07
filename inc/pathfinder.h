#ifndef PATHFINDER_H
#define PATHFINDER_H

#define P_SIZE 8

//structures
typedef struct s_island
{
    char *name;
    int index;
} island;

typedef struct s_route
{
    int *route;
    int paths;
} route;

void fileContents(char **mass);
void logic(char **mass);

#endif
