#include "libmx.h"

void  mx_printerr(char *a) {
    int j = 0;
    char i = a[0];
    while (i != '\0') {
        j += 1;
        i = a[j];
    }
    write(2, a, j);
}
