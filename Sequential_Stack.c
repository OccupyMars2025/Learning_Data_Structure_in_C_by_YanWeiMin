#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef int Status;
typedef int SElemType;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} *SqStack;

Status InitStack(SqStack S) {
    // construct an empty stack
    S->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;

    return OK;
}

Status GetTop(SqStack S, SElemType *e) {
    if (S->base == S->top) return ERROR;
    *e = *((S->top) - 1);
    return OK;
}

Status Push(SqStack S, SElemType e) {
    if (S->top - S->base >= S->stacksize) {
        S->base = (SElemType *) realloc(S->base,
                                        (S->stacksize + STACK_INCREMENT) * sizeof(SElemType));
        if (!S->base) exit(OVERFLOW);
        S->top = S->base + S->stacksize;
        S->stacksize += STACK_INCREMENT;
    }
    *(S->top)++ = e;

    return OK;
}

Status Pop(SqStack S, SElemType *e) {
    if (S->top == S->base) return ERROR;
    *e = *(--(S->top));

    return OK;
}
