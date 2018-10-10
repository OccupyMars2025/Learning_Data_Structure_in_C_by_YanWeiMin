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

Status ListInit_Sq(SqList *L)
{
    (*L) = (SqList) malloc(sizeof(struct SequenceList));
    if ((*L) == NULL)
        return OVERFLOW;
    (*L)->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if ((*L)->elem == NULL)
        return OVERFLOW;
    (*L)->length = 0;
    (*L)->listsize = LIST_INIT_SIZE;

    return OK;
}

Status ListInsert_Sq(SqList L, int i, ElemType e)
{
    int j;

    // legal scope: 0 <= i <= length
    if (L->length >= L->listsize) {
        L->elem = (ElemType *) realloc(L->elem,
                        (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (L->elem == NULL)
            return OVERFLOW;
        L->listsize += LIST_INCREMENT;
    }

    for (j = L->length - 1; j >= i; j--) {
        L->elem[j+1] = L->elem[j];
    }
    L->elem[i] = e;
    L->length++;

    return OK;
}

void ListPrint_Sq(SqList L)
{
    int i;

    for (i = 0; i < L->length; i++) {
        printf("%d, ", L->elem[i]);
    }
    printf("\n");
}

// key algorithm
int ListCompare_Sq(SqList La, SqList Lb)
{
    // La < Lb: return negative
    // La = Lb: return 0
    // La > Lb: return positive
    int i = 0;

    while (i < La->length && i < Lb->length && La->elem[i] == Lb->elem[i])
        i++;

    if (i < La->length) {
        if (i < Lb->length)
            return La->elem[i] - Lb->elem[i];
        else
            return 1;
    } else {
        if (i < Lb->length)
            return -1;
        else
            return 0;
    }
}
