#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // INT_MAX, INT_MIN, LONG_MAX, LONG_MIN

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// we assume INT_MAX is the maximum number the computer can represent,
// so we can't compute a number larger than INT_MAX
int main()
{
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MIN);
    int n = 20, i;
    int a[n];

    a[0] = 1;
    for (i = 1; i < n; i++) {
        if (a[i-1] > INT_MAX/(2 * i)) {
            fprintf(stderr, "\nerror: too large an integer\n");
            return OVERFLOW;
        }
        a[i] = a[i-1] * i * 2;
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}
