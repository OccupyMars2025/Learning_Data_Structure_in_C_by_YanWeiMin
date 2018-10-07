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
typedef char SElemType; // Caution!!!

typedef struct SequentialStack {
    SElemType *base;
    SElemType *top;
    int stacksize;
} *SqStack;

Status InitStack(SqStack *S) {
    // construct an empty stack
    (*S) = (SqStack) malloc(sizeof(struct SequentialStack));
    if (!(*S))
        exit(OVERFLOW);
    (*S)->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!((*S)->base))
        exit(OVERFLOW);
    (*S)->top = (*S)->base;
    (*S)->stacksize = STACK_INIT_SIZE;

    return OK;
}

Status GetTop(SqStack S, SElemType *e) {
    if (S->base == S->top)
        return ERROR;
    *e = *(S->top - 1);
    return OK;
}

Status Push(SqStack S, SElemType e) {
    if (S->top - S->base >= S->stacksize) {
        S->base = (SElemType *) realloc(S->base,
                                        (S->stacksize + STACK_INCREMENT) * sizeof(SElemType));
        if (!(S->base))
            return OVERFLOW;
        S->top = S->base + S->stacksize;
        S->stacksize += STACK_INCREMENT;
    }
    *(S->top)++ = e;
    return OK;
}

Status Pop(SqStack S, SElemType *e) {
    if (S->base == S->top)
        return ERROR;
    *e = *(--(S->top));
    return OK;
}

void ClearStack(SqStack S) {
    S->top = S->base;
}

Status StackEmpty(SqStack S) {
    if (S->top == S->base)
        return TRUE;
    else
        return FALSE;
}

void DestroyStack(SqStack *S) {
    free((*S)->base);
    free(*S);
}

// application of stack: edit a line
void LineEdit() {
    // use a stack to receive one line and then print out
    // the trimmed result
    SqStack S = NULL;
    int ch;
    SElemType e;
    SElemType *ptr = NULL;

    InitStack(&S);
    printf("Enter your code:\n");
    ch = getchar();
    while (ch != EOF) {
        while (ch != EOF && ch != '\n') {
            switch (ch) {
                case '#': Pop(S, &e);
                          break;
                case '@': ClearStack(S);
                          break;
                default : Push(S, ch);
                          break;
            }
            ch = getchar();
        }

        ptr = S->base;
        while (ptr < S->top) {
            printf("%c", *ptr);
            ++ptr;
        }
        printf("\n");
        ClearStack(S);

        if (ch != EOF)
            ch = getchar();
    }
    DestroyStack(&S);
}
