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

Status ListInit_WithoutHead(LinkList *L)
{
    (*L) = NULL;
    return OK;
}

Status ListInsert_WithoutHead(LinkList *L, int i, ElemType e)
{
    // Caution : LinkList *L
    int j = 0;
    LinkList p = *L;
    LinkList newnode;

    newnode = (LinkList) malloc(sizeof(Node));
    if (newnode == NULL) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    newnode->data = e;

    // without head node, we have to deal with i = 0 separately
    // and this is annoying
    if (i == 0) {
        if (*L != NULL) {
            newnode->next = *L;
            *L = newnode;
        } else {
            *L = newnode;
            newnode->next = NULL;
        }

        return OK;
    }

    if (p == NULL) {    // Now there must be at least one node
        fprintf(stderr, "error: index out of range\n");
        return INFEASIBLE;
    }
    while (p->next != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if (j != i-1) {
        fprintf(stderr, "error: index out of range\n");
        return INFEASIBLE;
    }
    newnode->next = p->next;
    p->next = newnode;

    return OK;
}

void ListPrint_WithoutHead(LinkList L)
{
    LinkList p = L;

    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
