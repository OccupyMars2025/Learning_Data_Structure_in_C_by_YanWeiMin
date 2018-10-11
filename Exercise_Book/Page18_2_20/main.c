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
} Node, *LinkList;

Status ListInit(LinkList *L);
Status ListInsert(LinkList L, int i, ElemType e);
void ListPrint(LinkList L);
void ListDeleteRepeatedElems(LinkList L);

int main()
{
    LinkList L;
    int n, i;
    ElemType e;

    ListInit(&L);
    printf("Enter # of elements:\n");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &e);
        ListInsert(L, i, e);
    }
    ListPrint(L);
    ListDeleteRepeatedElems(L);
    printf("After deleting repeated elements:\n");
    ListPrint(L);

    return 0;
}
