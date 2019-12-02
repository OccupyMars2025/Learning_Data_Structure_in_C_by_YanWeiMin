#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void init_stack(Stack* s)
{
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (s->base == NULL)
	{
		printf("\nmalloc failure!!");
		exit(OVERFLOW);
	}
	s->top = s->base;
	s->stack_space = STACK_INIT_SIZE;
}

void destroy_stack(Stack* s)
{
	free(s->base);
}

int is_empty(Stack* s)
{
	if (s->top == s->base)
		return 1;
	else
		return 0;
}

void push(Stack* s, SElemType* e)
{
	SElemType* temp;

	if (s->top - s->base >= s->stack_space)
	{
		temp = (SElemType*)realloc(s->base, (s->stack_space + STACK_INCREMENT) * sizeof(SElemType));
		if (temp == NULL)
		{
			printf("\nrealloc failure!!!");
			exit(OVERFLOW);
		}
		s->base = temp;
		s->top = s->base + s->stack_space;
		s->stack_space += STACK_INCREMENT;
	}
	*(s->top)++ = *e;
}

void pop(Stack* s, SElemType* e)
{
	if (s->top == s->base)
	{
		printf("\nempty stack!!!");
		exit(INFEASIBLE);
	}
	*e = *--(s->top);
}

void get_top(Stack* s, SElemType* e)
{
	if (s->top == s->base)
	{
		printf("\nempty stack!!!");
		exit(INFEASIBLE);
	}
	*e = *(s->top - 1);
}

int get_elem_number(Stack* s)
{
	return s->top - s->base;
}

