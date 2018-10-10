#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkedList;

Status ListInit(LinkedList *L);
Status ListInsert(LinkedList L, int i, ElemType e);
int ListLocate(LinkedList L, ElemType e);
void ListPrint(LinkedList L);

int main()
{
    LinkedList L;
    int index, n, i;
    ElemType e;

    ListInit(&L);
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &e);
        ListInsert(L, i, e);
    }
    ListPrint(L);

    printf("Enter the element you want to locate:\n");
    scanf("%d", &e);
    index = ListLocate(L, e);
    if (index != -1)
        printf("Location of element %d is: %d\n", e, index);
    else
        printf("Element %d is NOT in the list!\n", e);

    return 0;
}
