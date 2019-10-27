#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void recognize_pattern()
{
	char ch, flag;
	Stack stack;
	SDataType data;

	init_stack(&stack);
	printf("\nEnter a line of string:\n");
	flag = '0';
	ch = getchar();
	while (ch != '@')
	{
		if (flag == '0')
		{
			if (ch != '&')
				push(&stack, &ch);
			else
				flag = '1';
		}
		else
		{
			if (is_empty(&stack) == 0)
			{
				get_top(&stack, &data);
				if (data == ch)
					pop(&stack, &data);
			}
			else // Caution!!!
			{
				printf("\nDon't match");
				return;
			}
		}
		ch = getchar();
	}
	if (is_empty(&stack) == 1)
		printf("\nMatch");
	else
		printf("\nDon't match");
}