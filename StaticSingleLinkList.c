// use one-dimension array to describe linked list
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 30

typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType data;
    int cur;
} component, SLinkList[MAXSIZE];

void InitSpace_SL(SLinkList space)
{
    int i;

    for (i = 0; i < MAXSIZE-1; ++i)
        space[i].cur = i+1;
    space[MAXSIZE-1].cur = 0;
}

int Malloc_SL(SLinkList space)
{
    int i = space[0].cur;

    if (i)
        space[0].cur = space[i].cur;
    return i;
}

void Free_SL(SLinkList space, int k)
{
    if (k < 0 || k > MAXSIZE-1) {
        fprintf(stderr, "Index out of range!");
        return;
    }
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

int LocateElem_SL(SLinkList S, ElemType e)
{
    int i;

    i = S[0].cur;   // i refers to the first node
    while (i && S[i].data != e)
        i = S[i].cur;
    return i;
}

void difference(SLinkList space, int *S)
{
    // we assume that space is big enough
    // enter elements of set A and set B in order,
    // establish a static single link list (its head pointer is S)which represents
    // the union of A-B and B-A in the one-dimension array space
    // space[0].cur is the head pointer of the empty link list
    int nA, nB, i, j;
    int r;  // refer to current last node of A
    int p, k;  // p is the previous node of k
    ElemType e;

    InitSpace_SL(space);
    *S = Malloc_SL(space);
    r = *S;

    printf("Enter number of elements in set A:\n");
    scanf("%d", &nA);
    printf("\nEnter %d different integers of set A:\n", nA);
    for (i = 1; i <= nA; ++i) {
        j = Malloc_SL(space);
        scanf("%d", &(space[j].data));
        space[r].cur = j;   r = j;
    }
    space[r].cur = 0;    // end of the link list for set A

    // check each element e in B, if e is in A, then delete it;
    // if e is not in A, then add e
    printf("\nEnter number of elements in set B:\n");
    scanf("%d", &nB);
    printf("\nEnter %d different integers of set B:\n", nB);
    for (i = 1; i <= nB; ++i) {
        scanf("%d", &e);
        p = *S;   k = space[*S].cur;  // space[k] is the first node
        while (k != space[r].cur && space[k].data != e) {
            p = k;  k = space[k].cur;
        }
        if (k == space[r].cur) {  // e is not in set A
            j = Malloc_SL(space);
            space[j].data = e;
            space[j].cur = space[r].cur;
            space[r].cur = j;
        } else {        // e is in set A and delete e
            space[p].cur = space[k].cur;
            Free_SL(space, k);
            if (k == r) r = p;  // if end node is deleted, alter end pointer
        }
    }
}

// S is acquired by calling difference()
void PrintList(SLinkList space, int S)
{
    int i = space[S].cur;

    while (i != 0) {
        printf("%d -> ", space[i].data);
        i = space[i].cur;
    }
    printf("NULL\n");
}
