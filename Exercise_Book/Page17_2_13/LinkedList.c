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
    // i == 0 : insert after head node
    int j = -1;
    LinkedList p = L;
    LinkedList node;

    while (p->next != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if (j != i-1) {
        fprintf(stderr, "error: index out of range");
        return INFEASIBLE;
    }

    node = (LinkedList) malloc(sizeof(Node)); // Caution!!!
    if (node == NULL) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    node->data = e;
    node->next = p->next;
    p->next = node;

    return OK;
}

// key algorithm
int ListLocate(LinkedList L, ElemType e)
{
    int i = -1;
    LinkedList p = L;

    if (p->next == NULL) // Caution !!!
        return -1;

    while (p->next != NULL) {
        p = p->next;
        i++;
        if (p->data == e)
            break;
    }
    if (p->data == e)  // Caution !!!
        return i;
    return -1;
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
