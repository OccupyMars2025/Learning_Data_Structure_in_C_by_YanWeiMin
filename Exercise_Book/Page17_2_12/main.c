#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

typedef int Status;
typedef int ElemType;

typedef struct SequenceList
{
    ElemType *elem;  // base location
    int length;
    int listsize;
} *SqList;

Status ListInit_Sq(SqList *L);
Status ListInsert_Sq(SqList L, int i, ElemType e);
int ListCompare_Sq(SqList La, SqList Lb);
void ListPrint_Sq(SqList L);

int main()
{
    SqList La, Lb;
    int i, length_a, length_b;
    ElemType e;
    int result;

    ListInit_Sq(&La);
    ListInit_Sq(&Lb);
    printf("Enter lengths of list A and B:\n");
    scanf("%d", &length_a);
    scanf("%d", &length_b);

    printf("Enter %d integers of list A:\n", length_a);
    for (i = 0; i < length_a; i++) {
        scanf("%d", &e);
        ListInsert_Sq(La, i, e);
    }
    printf("Enter %d integers of list B:\n", length_b);
    for (i = 0; i < length_b; i++) {
        scanf("%d", &e);
        ListInsert_Sq(Lb, i, e);
    }

    ListPrint_Sq(La);
    ListPrint_Sq(Lb);
    result = ListCompare_Sq(La, Lb);
    if (result < 0)
        printf("La < Lb\n");
    else if (result > 0)
        printf("La > Lb\n");
    else
        printf("La = Lb\n");

    return 0;
}
