#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int ack_recursive(int m, int n)
{
	if (m == 0)
		return n + 1;
	else
	{
		if (n == 0)
			return ack_recursive(m - 1, 1);
		else
			return ack_recursive(m - 1, ack_recursive(m, n - 1));
	}
}

int ack_not_recursive(int m, int n)
{
	Stack stack;
	SElemType elem, elem2;
	int result;

	init_stack(&stack);
	elem.m = m; elem.n = n;
	push(&stack, &elem);
	do
	{
		get_top(&stack, &elem);
		while (elem.m)
		{
			while (elem.n)
			{
				elem.n--;
				push(&stack, &elem);
			}
			pop(&stack, &elem);
			elem.m--;
			elem.n = 1;
			push(&stack, &elem);
		}
		if (get_elem_number(&stack) > 1)
		{
			pop(&stack, &elem2);
			pop(&stack, &elem);
			elem.m--;
			elem.n = elem2.n + 1;
			push(&stack, &elem);
		}
	} while (get_elem_number(&stack) > 1 || stack.base->m != 0);

	result = stack.base->n + 1;
	destroy_stack(&stack);

	return result;
}
