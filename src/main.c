#include "pathfinder.h"
#include "../libmx/inc/libmx.h"
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        mx_printerr("usage: ./pathfinder [filename]");
        return 0;
    }
    char *contentFile = mx_file_to_str(argv[1]);
    if (contentFile == NULL)
    {
        mx_printerr("error: file");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        return 0;
    }
    char **mass = mx_sting_to_arr(contentFile, '\n');
    if (mx_strlen(contentFile) == 0)
    {
        mx_printerr("error: file");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        return 0;
    }
    fileContents(mass);
    return 0;
}
