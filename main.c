#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

Status fibonacci(int k, int m, int *fm);

int main()
{
    int k = 3, m = 10;
    int fm;

    fibonacci(k, m, &fm);
    printf("the %d-th item is:\n%d", m, fm);
    return 0;
}
