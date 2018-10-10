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
} Node, *LinkedList;

Status ListInit(LinkedList *L)
{
    (*L) = (LinkedList) malloc(sizeof(Node));
    if ((*L) == NULL) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    (*L)->next = NULL;
    return OK;
}

Status ListInsert(LinkedList L, int i, ElemType e)
{
    // legal scope: 0 <= i <= length
    int j = -1;
    LinkedList p = L;
    LinkedList node;

    while (p->next != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if (j != i-1) {
        fprintf(stderr, "error: index out of range\n");
        return ERROR;
    }

    node = (LinkedList) malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    node->data = e;
    node->next = p->next;
    p->next = node;

    return OK;
}

void ListPrint(LinkedList L)
{
    LinkedList p = L->next;

    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// key algorithm
int ListLength(LinkedList L)
{
    int length = 0;
    LinkedList p = L->next;

    while (p != NULL) {
        length++;
        p = p->next;
    }

    return length;
}
