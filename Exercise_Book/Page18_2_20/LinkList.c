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

void ListDeleteRepeatedElems(LinkList L)
{
    // assume L is non-decreasing
    LinkList p, q, r;

    if (L->next == NULL)
        return;

    p = L->next;
    while (p->next != NULL) {
        q = p->next;
        if (p->data == q->data) {
            r = q;
            q = q->next;
            free(r);
            while (q != NULL) {
                if (p->data != q->data)
                    break;
                r = q;
                q = q->next;
                free(r);
            }
            p->next = q;
        }
        if (q == NULL)
            break;
        p = q;
    }
}
