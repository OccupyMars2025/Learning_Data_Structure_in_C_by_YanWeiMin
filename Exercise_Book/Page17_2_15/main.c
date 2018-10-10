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
Status ListPrint(LinkList L);
LinkList ListMerge(LinkList La, LinkList Lb);

int main()
{
    LinkList La, Lb, Lc;
    int length_a, length_b, i;
    ElemType e;

    ListInit(&La);
    ListInit(&Lb);
    printf("Enter number of elements in lists La and Lb:\n");
    scanf("%d", &length_a);
    scanf("%d", &length_b);
    printf("Enter %d integers of La:\n", length_a);
    for (i = 0; i < length_a; i++) {
        scanf("%d", &e);
        ListInsert(La, i, e);
    }
    printf("Enter %d integers of Lb:\n", length_b);
    for (i = 0; i < length_b; i++) {
        scanf("%d", &e);
        ListInsert(Lb, i, e);
    }
    ListPrint(La);
    ListPrint(Lb);
    if (length_a < length_b)  // key point
        Lc = ListMerge(La, Lb);
    else
        Lc = ListMerge(Lb, La);
    printf("Merged list:\n");
    ListPrint(Lc);

    return 0;
}
