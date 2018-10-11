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

Status ListInit(LinkList *L)
{
    (*L) = (LinkList) malloc(sizeof(Node));
    if ((*L) == NULL) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    (*L)->next = NULL;
    return OK;
}

Status ListInsert(LinkList L, int i, ElemType e)
{
    int j = -1;
    LinkList p = L;
    LinkList newnode;

    while (p->next != NULL && j < i-1) {
        p = p->next;
        ++j;
    }
    if (j != i-1) {
        fprintf(stderr, "error: index out of range\n");
        return INFEASIBLE;
    }

    newnode = (LinkList) malloc(sizeof(Node));
    if (newnode == NULL) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    newnode->data = e;
    newnode->next = p->next;
    p->next = newnode;
    return OK;
}

void ListPrint(LinkList L)
{
    LinkList p = L->next;

    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void ListDeleteSub(LinkList L, ElemType mink, ElemType maxk)
{
    // assume L is non-decreasing
    // delete all elements that are > mink and < maxk
    LinkList p = L, q, r;

    while (p->next != NULL) {
        q = p->next;
        if (q->data > mink)
            break;
        p = q;
    }
    if (p->next == NULL)    // all elements <= mink
        return;
    // now q->data > mink
    if (q->data >= maxk)
        return;
    // now, q->data > mink and < maxk
    r = q->next;
    free(q);
    while (r != NULL) {
        if (r->data >= maxk)
            break;
        q = r;
        r = r->next;
        free(q);
    }
    p->next = r;
}
