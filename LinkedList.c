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

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status ListCreate_L(LinkList *L, int n)
{
    int i;
    LNode *p;
    ElemType e;

    *L = (LinkList) malloc(sizeof(LNode));
    if (*L == NULL)
        return OVERFLOW;
    (*L)->next = NULL;

    for (i = n; i > 0; --i) {
        p = (LNode *) malloc(sizeof(LNode));
        if (p == NULL)
            return OVERFLOW;
        scanf("%d", &e);
        p->data = e; p->next = (*L)->next;
        (*L)->next = p;
    }

    return OK;
}

Status GetElem_L(LinkList L, int i, ElemType *e)
{
    // when the i-th element exits, assign its value to e and
    // return OK , otherwise return ERROR
    int count = 1;
    LNode *p = L->next;

    while (p && count < i) {
        p = p->next;
        ++count;
    }
    if (!p || count > i)
        return ERROR;
    *e = p->data;
    return OK;
}

// no need to use "LinkList *L", L is itself a pointer
Status ListInsert_L(LinkList L, int i, ElemType e)
{
    // insert e before the i-th element
    LNode *p = L;
    LNode *s = NULL;
    int j = 0;

    while (p && j < i-1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i-1)
        return ERROR;
    s = (LNode *) malloc(sizeof(LNode));
    if (!s)
        return OVERFLOW;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_L(LinkList L, int i, ElemType *e)
{
    LNode *p = L;
    int j = 0;
    LNode *q = NULL;

    while (p->next && j < i-1) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i-1)
        return ERROR;
    q = p->next;    p->next = q->next;
    *e = q->data;   free(q);     // Caution!!!
    return OK;
}

void ListPrint_L(LinkList L)
{
    LNode *p = L->next;

    if (p == NULL)
        printf("empty list!!!\n");
    else {
        do {
            printf("%d -> ", p->data);
            p = p->next;
        } while (p != NULL);
        printf("NULL\n");
    }
}

void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc)
{
    // merge two non-decreasing lists La and Lb to get
    // a non-decreasing list Lc
    LNode *pa, *pb, *pc;
    pa = (*La)->next; pb = (*Lb)->next;
    pc = *Lc = *La;

    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(*Lb);
}

