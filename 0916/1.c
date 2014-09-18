//int ar[m][n]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ** initArry(int m, int n)
{
    int **ar = (int **)calloc(m, sizeof(int *));
    for (int i = 0; i < n; i++) {
        *(ar + i) = (int *)calloc(n, sizeof(int));
    }
    return ar;
}

