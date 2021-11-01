#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right)
{
    int l = left;
    int r = right;
    char *p = arr[(r + l) / 2];
    int count = 0;

    if (arr == NULL)
    {
        return -1;
    }
    while (l < r)
    {
        while (mx_strlen(arr[l]) < mx_strlen(p))
        {
            l += 1;
        }
        while (mx_strlen(arr[r]) > mx_strlen(p))
        {
            r -= 1;
        }
        if (l <= r)
        {
            if (mx_strlen(arr[r]) != mx_strlen(arr[l]))
            {
                char *temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                count += 1;
            }
            r -= 1;
            l += 1;
        }
    }

    if (l != right)
    {
        count = count + mx_quicksort(arr, l, right);
    }
    if (r != left)
    {
        count = count + mx_quicksort(arr, left, r);
    }
    return count;
}
