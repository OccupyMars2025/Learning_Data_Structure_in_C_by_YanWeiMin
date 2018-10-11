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
    // Caution: LinkList *L
    int j = 0;
    LinkList p = (*L);
    LinkList newnode;

    newnode = (LinkList) malloc(sizeof(Node));
    if (newnode == NULL) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    newnode->data = e;

    if (p == NULL) {
        if (i != 0) {
            fprintf(stderr, "error: index out of range\n");
            return INFEASIBLE;
        }
        newnode->next = NULL;
        (*L) = newnode;
        return OK;
    }

    // Now p != NULL
    if (i == 0) {  // we cannot get prior node, so deal with it separately
        newnode->next = (*L);
        *L = newnode;
        return OK;
    }

    // Now p != NULL and i != 0
    // we can get prior node and insert new node after it
    while (p->next != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if (j != i-1) {
        fprintf(stderr, "error: index out of range");
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

Status ListDelete_WithoutHead(LinkList *L, int i)
{
    // Caution: LinkList *L
    int j = 0;
    LinkList p = *L;
    LinkList node_deleted;

    if (p == NULL) {
        fprintf(stderr, "error: list is empty, cannot delete\n");
        return INFEASIBLE;
    }

    if (p->next == NULL) {
        if (i != 0) {
            fprintf(stderr, "error: index out of range\n");
            return INFEASIBLE;
        }
        node_deleted = *L;
        *L = NULL;
        free(node_deleted);
        return OK;
    }

    // Now, there are at least 2 nodes
    if (i == 0) {
        node_deleted = *L;
        *L = (*L)->next;
        free(node_deleted);
        return OK;
    }

    // get the node prior to the node you want to delete
    while (p->next != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if (j != i-1) {
        fprintf(stderr, "error: index out of range\n");
        return INFEASIBLE;
    }
    node_deleted = p->next;
    p->next = node_deleted->next;
    free(node_deleted);
    return OK;
}
