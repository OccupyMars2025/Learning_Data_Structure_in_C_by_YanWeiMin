#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void init_stack(Stack* s)
{
	s->base = (SDataType*)malloc(STACK_INIT_SIZE * sizeof(SDataType));
	if (s->base == NULL)
	{
		printf("\nmalloc failure!!!");
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

void push(Stack* s, SDataType data)
{
	SDataType* temp;

	if (s->top - s->base >= s->stack_space)
	{
		temp = (SDataType*)realloc(s->base, (s->stack_space + STACK_INCREMENT) * sizeof(SDataType));
		if (temp == NULL)
		{
			printf("\nrealloc failure!!!");
			free(s->base);
			exit(OVERFLOW);
		}
		s->base = temp;
		s->top = s->base + s->stack_space;
		s->stack_space += STACK_INCREMENT;
	}
	*(s->top)++ = data;
}

void pop(Stack* s, SDataType* data)
{
	if (s->top == s->base)
	{
		printf("\nempty stack!!!");
		exit(OVERFLOW);
	}
	*data = *--(s->top);
}
