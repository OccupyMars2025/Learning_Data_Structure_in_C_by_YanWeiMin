#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

Status fibonacci(int k, int m, int *fm) {
    // find out the m-th item in a fibonacci sequence
    // with order k
    if (k < 2 || m < 0)
        return ERROR;
    if (m >= 0 && m < k-1) {
        *fm = 0;
        return OK;
    }
    if (m == k-1) {
        *fm = 1;
        return OK;
    }

    int f[m+1];
    int i;

    for (i = 0; i < k-1; i++) {
        f[i] = 0;
    }
    f[k-1] = 1;
    f[k] = 1;
    for (i = k+1; i <= m; i++) {
        f[i] = f[i-1] - f[i-k-1] + f[i-1];
    }

    for (i = 0; i <= m; i++) {
        printf("%d, ", f[i]);
    }
    printf("\n");

    *fm = f[m];
    return OK;
}
