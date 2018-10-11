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
        j++;
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

Status ListDelete(LinkList L, int i)
{
    // similar to ListInsert()
    int j = -1;
    LinkList p = L;
    LinkList node_deleted;

    if (p->next == NULL) {
        fprintf(stderr, "error: list is empty, cannot delete\n");
        return INFEASIBLE;
    }

    // get the node prior to the node you want to delete
    while (p->next->next != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if (j != i-1) {
        fprintf(stderr, "error: index out of range\n");
        return INFEASIBLE;
    }
    node_deleted = p->next;
    p->next = node_deleted->next;
    free(node_deleted);  // Caution!!!

    return OK;
}
