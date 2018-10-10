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

// with head node
Status ListInit(LinkList *L);
Status ListInsert(LinkList L, int i, ElemType e);
void ListPrint(LinkList L);

// without head node
Status ListInit_WithoutHead(LinkList *L);
Status ListInsert_WithoutHead(LinkList *L, int i, ElemType e);
void ListPrint_WithoutHead(LinkList L);

int main()
{
    LinkList La, Lb;
    int na, nb, i;
    ElemType e;

    // with head node
    printf("Test linked list with head node:\n");
    ListInit(&La);
    printf("Enter number of elements in La:\n");
    scanf("%d", &na);
    printf("Enter %d integers in La:\n", na);
    for (i = 0; i < na; i++) {
        scanf("%d", &e);
        ListInsert(La, i, e);
    }
    ListPrint(La);

    // without head node
    printf("\n\nTest linked list without head node:\n");
    ListInit_WithoutHead(&Lb);
    printf("Enter number of elements in Lb:\n");
    scanf("%d", &nb);
    printf("Enter %d integers in Lb:\n", nb);
    for (i = 0; i < nb; i++) {
        scanf("%d", &e);
        ListInsert_WithoutHead(&Lb, i, e);  // Caution : &Lb
    }
    ListPrint_WithoutHead(Lb);
    return 0;
}
