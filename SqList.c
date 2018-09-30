#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} SqList;

Status InitList_Sq(SqList *L)
{
    // create an empty list
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;

    return OK;
}

Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
    // insert e before the i-th location
    // legal scope:   1 <= i <= length + 1
    ElemType *p, *q;
    ElemType *newbase;

    if (i < 1 || i > L->length + 1)
        exit(ERROR);
    if (L->length >= L->listsize) {
        newbase = (ElemType *) realloc(L->elem,
                                       (L->listsize + LIST_INCREMENT)*sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LIST_INCREMENT;
    }
    q = &(L->elem[i-1]);
    for (p = &(L->elem[L->length-1]); p >= q; p--) // all elems at or after i-th location move right by
        *(p+1) = *p;                             // by one step
    *q = e;
    L->length++;

    return OK;
}

Status ListDelete_Sq(SqList *L, int i, ElemType *e)
{
    // legal scope: 1 <= i <= length
    ElemType *p, *q;

    if (i < 1 || i > L->length)
        return ERROR;
    p = &(L->elem[i-1]);
    *e = *p;
    q = L->elem + L->length - 1;
    while (p < q) {
        *p = *(p+1);
        ++p;
    }
    --(L->length);

    return OK;
}

int LocateElem_Sq(SqList L, ElemType e,
                  Status (*compare)(ElemType, ElemType))
{
    int i = 1;
    ElemType *p = L.elem;

    while (i <= L.length && !(*compare)(*p++, e))
        ++i;
    if (i <= L.length)
        return i;
    else
        return 0;
}

Status ElemEqual(ElemType e1, ElemType e2)
{
    if (e1 != e2)
        return FALSE;
    else
        return TRUE;
}

void MergeList_Sq(SqList La, SqList Lb, SqList *Lc)
{
    // non-decreasing lists La and Lb merge to form
    // an non-decreasing list Lc
    ElemType *pa, *pb, *pc;
    ElemType *pa_last, *pb_last;

    Lc->listsize = Lc->length = La.length + Lb.length;
    pc = Lc->elem = (ElemType *) malloc((Lc->listsize)*sizeof(ElemType));
    if (!(Lc->elem))
        exit(OVERFLOW);
    pa = La.elem; pb = Lb.elem;
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    while (pa <= pa_last)
        *pc++ = *pa++;
    while (pb <= pb_last)
        *pc++ = *pb++;
}

void PrintList_Sq(SqList L)
{
    int i;

    printf("\nThe current list:\n");
    for (i = 0; i < L.length; ++i)
        printf("%d,", L.elem[i]);
    printf("\n");
}
