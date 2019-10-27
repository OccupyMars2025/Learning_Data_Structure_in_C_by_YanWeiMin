#include "my_stack.h"
#include<stdio.h>
#include<stdlib.h>

void init_stack(Stack* stack)
{
	stack->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (stack->base == NULL)
	{
		printf("\nmalloc failure!!!");
		exit(1);
	}
	stack->top = stack->base;
	stack->stack_size = STACK_INIT_SIZE;
}

int is_empty(Stack* stack)
{
	if (stack->top == stack->base)
		return 1;
	else
		return 0;
}

void push(Stack* stack, SElemType elem)
{
	SElemType* temp;

	if (stack->top - stack->base >= stack->stack_size)
	{
		temp = (SElemType*)realloc(stack->base, (stack->stack_size + STACK_INCREMENT) * sizeof(SElemType));
		if (temp == NULL)
		{
			free(stack->base);
			printf("\nrealloc failure!!!");
			exit(1);
		}
		stack->base = temp;
		stack->top = stack->base + stack->stack_size;
		stack->stack_size += STACK_INCREMENT;
	}
	*(stack->top) = elem;
	++(stack->top);
}

void pop(Stack* stack, SElemType* elem)
{
	if (stack->top > stack->base)
	{
		--(stack->top);
		*elem = *(stack->top);
	}
	else
	{
		printf("\nempty stack!!!");
	}
}

void get_top(Stack* stack, SElemType* elem)
{
	if (stack->top > stack->base)
	{
		*elem = *(stack->top - 1);
	}
	else
	{
		printf("\nempty stack!!!");
	}
}
