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

Status ListInit(LinkedList *L);
Status ListInsert(LinkedList L, int i, ElemType e);
void ListPrint(LinkedList L);
int ListLength(LinkedList L);

int main()
{
    LinkedList L;
    int length;
    int i, n;
    ElemType e;

    ListInit(&L);
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &e);
        ListInsert(L, i, e);
    }
    ListPrint(L);
    length = ListLength(L);
    printf("Length of the list: %d\n", length);
    return 0;
}
