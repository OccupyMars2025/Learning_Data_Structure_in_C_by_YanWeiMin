// use static single link list to represent the union of
// A-B and B-A (A, B are two sets)
// the key function is difference()

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
} component, SLinkList[MAXSIZE];  // Caution!!!

void difference(SLinkList space, int *S);
void PrintList(SLinkList space, int S);

int main()
{
    SLinkList space;
    int S;

    difference(space, &S);
    PrintList(space, S);
    return 0;
}

