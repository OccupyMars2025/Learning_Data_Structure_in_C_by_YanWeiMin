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

Status ListInit_Sq(SqList *L);
Status ListInsert_Sq(SqList L, int i, ElemType e);
void ListPrint_Sq(SqList L);
Status IncreasingListInsert_Sq(SqList L, ElemType e);

int main()
{
    SqList L;
    ElemType e;
    int n, i;

    ListInit_Sq(&L);
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    printf("Enter %d integers in non-increasing order:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &e);
        ListInsert_Sq(L, 0, e);
    }
    printf("Now you get an non-decreasing list:\n");
    ListPrint_Sq(L);

    printf("Enter an integer you want to insert:\n");
    scanf("%d", &e);
    IncreasingListInsert_Sq(L, e);
    ListPrint_Sq(L);

    return 0;
}

Status IncreasingListInsert_Sq(SqList L, ElemType e)  // key algorithm
{
    int i;

    if (L->length >= L->listsize) {
        L->elems = (ElemType *) realloc(L->elems,
                                        (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (L->elems == NULL)
            return OVERFLOW;
        L->listsize += LIST_INCREMENT;
    }

    i = L->length - 1;
    while (i >= 0 && e < L->elems[i]) {
        L->elems[i+1] = L->elems[i];
        i--;
    }
    L->elems[i+1] = e;
    L->length++;

    return OK;
}
