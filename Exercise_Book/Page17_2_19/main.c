#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0
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
void ListDeleteSub(LinkList L, ElemType mink, ElemType maxk);

int main()
{
    LinkList L;
    int n, i;
    ElemType e, mink, maxk;
    int go_on = YES;

    ListInit(&L);
    printf("Enter # of elements:\n");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &e);
        ListInsert(L, i, e);
    }
    ListPrint(L);
    do {
        printf("Enter mink and maxk:\n");
        scanf("%d", &mink);
        scanf("%d", &maxk);
        ListDeleteSub(L, mink, maxk);
        ListPrint(L);
        printf("Continue?(1=yes, 0=no):\n");
        scanf("%d", &go_on);
    } while (go_on == YES);

    return 0;
}
