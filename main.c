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

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;     // LinkList is the pointer to the head node

Status ListCreate_L(LinkList *L, int n);
Status ListInsert_L(LinkList L, int i, ElemType e);
Status ListDelete_L(LinkList L, int i, ElemType *e);
void ListPrint_L(LinkList L);
void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc);

int main()
{
    LinkList L, L2, Lc;
    ElemType e = 11;
    ListCreate_L(&L, 5);
    ListPrint_L(L);

    ListInsert_L(L, 1, e);
    e = 12;
    ListInsert_L(L, 2, e);
    e = 13;
    ListInsert_L(L, 3, e);
    ListPrint_L(L);

    ListDelete_L(L, 2, &e);
    ListPrint_L(L);
    printf("\n the second element = %d\n", e);
    ListDelete_L(L, 1, &e);
    ListDelete_L(L, 1, &e);
    ListPrint_L(L);

    printf("\nCreate the second list:\n");
    ListCreate_L(&L2, 5);
    MergeList_L(&L, &L2, &Lc);
    ListPrint_L(Lc);
    ListPrint_L(L);

    return 0;
}
