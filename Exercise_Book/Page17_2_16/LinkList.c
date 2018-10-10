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
    LinkList new_node;

    while (p->next != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if (j != i-1) {
        fprintf(stderr, "error: index out of range\n");
        return INFEASIBLE;
    }

    new_node = (LinkList) malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    new_node->data = e;
    new_node->next = p->next;
    p->next = new_node;

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

// key algorithm
Status DeleteAndInsertSub(LinkList La, LinkList Lb, int i, int j, int len)
{
    /* delete consecutive len elements from i-th element(including i-th element) of La,
       insert the deleted elements before j-th element of Lb*/

    LinkList p = La, q, s = Lb;
    LinkList original_q_next;   // help remember the original node
    int k;

    k = -1;
    while (p->next != NULL && k < i-1) {
        p = p->next;
        k++;
    }
    if (k != i-1) {
        fprintf(stderr, "error: index out of range\n");
        return INFEASIBLE;
    }

    q = p;
    while (q->next != NULL && k < i+len-1) {
        q = q->next;
        k++;
    }
    if (k != i+len-1) {
        fprintf(stderr, "error: index out of range\n");
        return INFEASIBLE;
    }

    k = -1;
    while (s->next != NULL && k < j-1) {
        s = s->next;
        k++;
    }
    if (k != j-1) {
        fprintf(stderr, "error: index out of range\n");
        return INFEASIBLE;
    }

    // Now we have found all the needed nodes
    original_q_next = q->next;
    q->next = s->next;
    s->next = p->next;
    p->next = original_q_next;

    return OK;
}
