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

typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

Status CreateList_DuL(DuLinkList *L);
Status ListInsert_DuL(DuLinkList L, int i, ElemType e);
Status ListDelete_DuL(DuLinkList L, int i, ElemType *e);
void ListPrint_DuL(DuLinkList L);
int ListLength_DuL(DuLinkList L);

int main()
{
    DuLinkList L = NULL;
    int n, i, len;
    ElemType e;

    CreateList_DuL(&L);
    printf("Number of integers you want to enter:\n");
    scanf("%d", &n);
    printf("Please enter %d integers:\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &e);
        ListInsert_DuL(L, 0, e);
    }
    ListPrint_DuL(L);
    len = ListLength_DuL(L);
    printf("Length of the list:%d\n", len);

    return 0;
}
