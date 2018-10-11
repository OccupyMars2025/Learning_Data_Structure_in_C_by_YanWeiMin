#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0
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
Status ListDelete(LinkList L, int i);

// without head node
Status ListInit_WithoutHead(LinkList *L);
Status ListInsert_WithoutHead(LinkList *L, int i, ElemType e);
void ListPrint_WithoutHead(LinkList L);
Status ListDelete_WithoutHead(LinkList *L, int i);

int main()
{
    LinkList La, Lb;
    int na, nb, i;
    ElemType e;
    int go_on = YES;

    // test linked list with head node
    ListInit(&La);
    printf("Enter # of elements in La:\n");
    scanf("%d", &na);
    printf("Enter %d integers in La:\n", na);
    for (i = 0; i < na; i++) {
        scanf("%d", &e);
        ListInsert(La, 0, e);
    }
    ListPrint(La);
    do {
        printf("Enter location of element you want to delete:\n");
        scanf("%d", &i);
        ListDelete(La, i);
        ListPrint(La);
        printf("Continue?(1=yes, 0=no):\n");
        scanf("%d", &go_on);
    } while (go_on == YES);

    // test linked list without head node
    ListInit_WithoutHead(&Lb);
    printf("Enter # of elements in Lb:\n");
    scanf("%d", &nb);
    printf("Enter %d integers in Lb:\n", nb);
    for (i = 0; i< nb; ++i) {
        scanf("%d", &e);
        ListInsert_WithoutHead(&Lb, 0, e);
    }
    ListPrint_WithoutHead(Lb);
    do {
        printf("Enter location of element you want to delete:\n");
        scanf("%d", &i);
        ListDelete_WithoutHead(&Lb, i);
        ListPrint_WithoutHead(Lb);
        printf("Continue?(1=yes, 0=no):\n");
        scanf("%d", &go_on);
    } while (go_on == YES);

    return 0;
}
