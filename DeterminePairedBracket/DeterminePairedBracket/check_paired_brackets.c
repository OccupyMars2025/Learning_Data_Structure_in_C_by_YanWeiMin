#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void check_paired_brackets()
{
	int is_matched_brackets(char ch1, char ch2);
	int is_left_bracket(char ch);
	int is_right_bracket(char ch);

	Stack stack;
	char ch;
	SElemType elem;

	init_stack(&stack);
	printf("\nEnter an expression:\n");
	ch = getchar();
	while (ch != '\n')
	{
		if (is_left_bracket(ch) == 1)
			push(&stack, &ch);
		else if (is_right_bracket(ch) == 1)
		{
			if (is_empty(&stack) == 1)
			{
				printf("\nThere are unpaired brackets!!!");
				return;
			}
			pop(&stack, &elem);
			if (is_matched_brackets(elem, ch) == 0)
			{
				printf("\nThere are unpaired brackets!!!");
				return;
			}
		}
		ch = getchar();
	}
	if (is_empty(&stack) == 1)
		printf("\nAll brackets are paired!!!");
	else
		printf("\nThere are unpaired brackets!!!");
	destroy_stack(&stack);
}

int is_left_bracket(char ch)
{
	switch (ch)
	{
	case '{':
	case '[':
	case '(':
		return 1;
		break;
	default:
		return 0;
		break;
	}
}

int is_right_bracket(char ch)
{
	switch (ch)
	{
	case '}':
	case ']':
	case ')':
		return 1;
		break;
	default:
		return 0;
		break;
	}
}

int is_matched_brackets(char ch1, char ch2)
{
	if ((ch1 == '{' && ch2 == '}') || (ch1 == '[' && ch2 == ']') || (ch1 == '(' && ch2 == ')'))
		return 1;
	else
		return 0;
}