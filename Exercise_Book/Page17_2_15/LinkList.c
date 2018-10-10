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
    LinkList node;

    while (p->next != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if (j != i-1) {
        fprintf(stderr, "error: index out of range\n");
        return INFEASIBLE;
    }

    node = (LinkList) malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    node->data = e;
    node->next = p->next;
    p->next = node;

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

int ListLength(LinkList L)
{
    int length = 0;
    LinkList p = L->next;

    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

// key algorithm
LinkList ListMerge(LinkList La, LinkList Lb)
{
    LinkList pa = La;

    while (pa->next != NULL)
        pa = pa->next;
    pa->next = Lb->next;
    free(Lb);

    return La;
}
