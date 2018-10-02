/* double circular linked list implementation */

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

Status CreateList_DuL(DuLinkList *L)
{
    // Caution !!!:  (DuLinkList L) won't work
    // create only the head node
    *L = (DuLinkList) malloc(sizeof(DuLNode));
    if (!(*L)) return OVERFLOW;
    (*L)->next = *L;
    (*L)->prior = *L;
    return OK;
}

DuLinkList GetElemP_DuL(DuLinkList L, int i)
{
    // legal scope: 0 <= i <= listlength
    // i == 0 refers to the head node
    DuLinkList p = L;
    int j = 0;

    while (p != L->prior && j < i) {  // p != L->prior
        p = p->next;
        ++j;
    }
    if (j == i)
        return p;
    else
        return NULL;
}

Status ListInsert_DuL(DuLinkList L, int i, ElemType e)
{
    // legal scope: 0 <= i <= listlength
    // insert before the i-th element
    DuLinkList p;  // pointer to the i-th node
    DuLinkList node;

    if (!(p = GetElemP_DuL(L, i))) {
        fprintf(stderr, "error: index out of range!");
        return ERROR;
    }
    node = (DuLinkList) malloc(sizeof(DuLNode));
    node->data = e;
    p->prior->next = node;
    node->prior = p->prior;
    node->next = p;
    p->prior = node;

    return OK;
}

Status ListDelete_DuL(DuLinkList L, int i, ElemType *e)
{
    //legal scope: 0 <= i <= listlength
    DuLinkList p;

    if (!(p = GetElemP_DuL(L, i))) {
        fprintf(stderr, "error: index out of range!");
        return ERROR;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);

    return OK;
}

void ListPrint_DuL(DuLinkList L)
{
    DuLinkList p = L->next;

    while (p != L) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int ListLength_DuL(DuLinkList L)
{
    DuLinkList p = L;
    int len = 0;

    while (p != L->prior) {
        p = p->next;
        ++len;
    }

    return len;
}
