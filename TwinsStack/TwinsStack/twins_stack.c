#include<stdio.h>
#include<stdlib.h>
#include "twins_stack.h"

void init_stack(Twins_Stack* ts)
{
	ts->base0 = (SDataType*)malloc(STACK_SPACE * sizeof(SDataType));
	if (ts->base0 == NULL)
	{
		printf("\nmalloc failure!!!");
		exit(OVERFLOW);
	}
	ts->top0 = ts->base0;
	ts->top1 = ts->base1 = ts->base0 + STACK_SPACE - 1;
}

void destroy_stack(Twins_Stack* ts)
{
	free(ts->base0);
}

void push(Twins_Stack* ts, int which, SDataType data)
{
	if (ts->top0 == ts->top1)
	{
		printf("\nError: stack space is full!!!");
		exit(OVERFLOW);
	}
	if (which == 0)
	{
		*(ts->top0)++ = data;
	}
	else if (which == 1)
	{
		*(ts->top1)-- = data;
	}
	else
	{
		printf("\nError: choose stack 0 or stack 1");
		exit(INFEASIBLE);
	}
}

void pop(Twins_Stack* ts, int which, SDataType* data)
{
	if (which == 0)
	{
		if (ts->base0 == ts->top0)
		{
			printf("\nWrong: stack 0 is empty!!!");
			exit(INFEASIBLE);
		}
		*data = *--(ts->top0);
	}
	else if (which == 1)
	{
		if (ts->base1 == ts->top1)
		{
			printf("\nWrong: stack 1 is empty!!!");
			exit(INFEASIBLE);
		}
		*data = *++(ts->top1);
	}
	else
	{
		printf("\nError: choose stack 0 or stack 1");
		exit(INFEASIBLE);
	}
}

void print_stack(Twins_Stack* ts, int which)
{
	SDataType* p;

	if (which == 0)
	{
		printf("\n====stack 0=====\n");
		p = ts->base0;
		while (p != ts->top0)
		{
			printf("%d, ", *p++);
		}
	}
	else if (which == 1)
	{
		printf("\n====stack 1=====\n");
		p = ts->base1;
		while (p != ts->top1)
		{
			printf("%d, ", *p--);
		}
	}
	printf("\n");
}

int is_empty(Twins_Stack* ts, int which)
{
	if (which == 0)
	{
		if (ts->base0 == ts->top0)
			return 1;
		else
			return 0;
	}
	else if(which == 1)
	{
		if (ts->base1 == ts->top1)
			return 1;
		else
			return 0;
	}
	else
	{
		printf("\nWrong: choose stack_0 or stack_1");
		return 1;
	}
}
