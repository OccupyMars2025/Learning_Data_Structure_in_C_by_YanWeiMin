#include <stdio.h>
#include <stdlib.h>

void descending(void);

int main()
{
    descending();
    return 0;
}

void descending(void)
{
    int a[3];
    int i, j, temp;
    int n = 3;

    printf("Enter 3 integers:\n");
    scanf("%d", a);
    scanf("%d", a+1);
    scanf("%d", a+2);
    printf("Print them out in an non-increasing order:\n");

    for (i = 0; i < n; ++i) {
        for (j = i+1; j < n; ++j) {
            if (a[j] > a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d,", a[i]);
    }
    printf("\n");
}
