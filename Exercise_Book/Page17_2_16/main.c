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

Status ListInit(LinkList *L);
Status ListInsert(LinkList L, int i, ElemType e);
void ListPrint(LinkList L);
Status DeleteAndInsertSub(LinkList La, LinkList Lb, int i, int j, int len);

int main()
{
    LinkList La, Lb;
    int na, nb, k;
    int i, len, j;  // refer to DeleteAndInsertSub()
    ElemType e;

    ListInit(&La);
    ListInit(&Lb);
    printf("Enter number of elements in La and Lb, respectively:\n");
    scanf("%d", &na);
    scanf("%d", &nb);
    printf("Enter %d integers of La:\n", na);
    for (k = 0; k < na; k++) {
        scanf("%d", &e);
        ListInsert(La, k, e);
    }
    printf("Enter %d integers of Lb:\n", nb);
    for (k = 0; k < nb; k++) {
        scanf("%d", &e);
        ListInsert(Lb, k, e);
    }
    ListPrint(La);
    ListPrint(Lb);

    printf("Enter i, len, j:\n");
    scanf("%d", &i);
    scanf("%d", &len);
    scanf("%d", &j);
    DeleteAndInsertSub(La, Lb, i, j, len);
    printf("After deletion and insertion:\n");
    ListPrint(La);
    ListPrint(Lb);

    return 0;
}
