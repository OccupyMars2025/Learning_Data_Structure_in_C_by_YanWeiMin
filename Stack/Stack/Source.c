#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define OVERFLOW 2
#define OK 3
#define INFEASIBLE 4
#define ERROR 5

#define STACK_INIT_SIZE 2
#define STACK_INCREMENT 3

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType* base;
	ElemType* top;
	int stack_size;
} SqStack;

int main() {
	void edit_line();

	edit_line();

	return 0;
}

void edit_line() {
	Status stack_init(SqStack * s);
	Status get_top(SqStack * s, ElemType * e);
	Status push(SqStack * s, ElemType e);
	Status pop(SqStack * s, ElemType * e);
	int is_empty(SqStack * s);
	void clear_stack(SqStack * s);
	void destroy_stack(SqStack * s);

	SqStack s, s2;
	char ch;
	ElemType e;

	stack_init(&s);
	stack_init(&s2);
	ch = getchar();
	while (ch != EOF)
	{
		while (ch != EOF && ch != '\n')
		{
			switch (ch) {
				case '#': 
					pop(&s, &e);
					break;
				case '@':
					clear_stack(&s);
					break;
				default:
					push(&s, ch);
			}
			ch = getchar();
		}
		while (!is_empty(&s))
		{
			pop(&s, &e);
			push(&s2, e);
		}
		while (!is_empty(&s2))
		{
			pop(&s2, &e);
			printf("%c", e);
		}
		printf("\n");
		if (ch != EOF)
			ch = getchar();
	}
}

void convert() {
	Status stack_init(SqStack * s);
	Status get_top(SqStack * s, ElemType * e);
	Status push(SqStack * s, ElemType e);
	Status pop(SqStack * s, ElemType * e);
	int is_empty(SqStack * s);

	SqStack s;
	int n, N;
	ElemType e;

	stack_init(&s);
	printf("Enter shu zhi:");
	scanf_s("%d", &n);
	printf("Enter a positive integer:");
	scanf_s("%d", &N);
	while (N)
	{
		push(&s, N % n);
		N = N / n;
	}
	while (!is_empty(&s))
	{
		pop(&s, &e);
		printf("%d", e);
	}
	printf("\n");
}

int is_empty(SqStack* s) {
	if (s->top == s->base)
		return 1;
	else
		return 0;
}

Status stack_init(SqStack* s) {
	s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
		exit(OVERFLOW);
	s->top = s->base;
	s->stack_size = STACK_INIT_SIZE;

	return OK;
}

Status get_top(SqStack* s, ElemType* e) {
	if (s->top == s->base)
		return ERROR;
	*e = *(s->top - 1);

	return OK;
}

Status push(SqStack* s, ElemType e) {
	ElemType* p;

	if (s->top - s->base >= s->stack_size) {
		p = (ElemType*)realloc(s->base, (s->stack_size + STACK_INCREMENT) * sizeof(ElemType));
		if (!p) {
			free(s->base);
			exit(OVERFLOW);
		}
		s->base = p;
		s->top = s->base + s->stack_size;
		s->stack_size += STACK_INCREMENT;
	}
	*s->top++ = e;
	
	return OK;
}

Status pop(SqStack* s, ElemType* e) {
	if (s->top == s->base)
		return ERROR;
	*e = *--s->top;

	return OK;
}

void clear_stack(SqStack* s) {
	s->top = s->base;
}

void destroy_stack(SqStack* s) {
	free(s->base);
	s->base = NULL;
	s->top = NULL;
}


