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

typedef struct SequenceList {
    ElemType *elems; // base location
    int length;   // current length
    int listsize; // allocated storage
} *SqList;

Status ListInit_Sq(SqList *L)
{
    (*L) = (SqList) malloc(sizeof(struct SequenceList));
    if ((*L) == NULL) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    (*L)->elems = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (((*L)->elems) == NULL) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    (*L)->length = 0;
    (*L)->listsize = LIST_INIT_SIZE;
    return OK;
}

Status ListInsert_Sq(SqList L, int i, ElemType e)
{
    int j;

    // legal scope: 0 <= i <= length
    if (i < 0 || i > L->length)
        return INFEASIBLE;

    // allocate more storage
    if (L->length >= L->listsize) {
        L->elems = (ElemType *) realloc(L->elems,
                                        (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (L->elems == NULL)
            return OVERFLOW;
        L->listsize += LIST_INCREMENT;
    }

    for (j = L->length - 1; j >= i; j--) {
        L->elems[j+1] = L->elems[j];
    }
    L->elems[i] = e;
    L->length++;

    return OK;
}

void ListPrint_Sq(SqList L)
{
    int i;

    for (i = 0; i < L->length; i++) {
        printf("%d, ", L->elems[i]);
    }
    printf("\n");
}
