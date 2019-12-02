#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

/*
	enter an arithmetic expression which contains only 0~9
	and + - * / ( ), transform it to a Reverse Polish Notation
*/
void get_reverse_polish_notation(Stack* result_stack)
{
	Stack operator_stack;
	int ch;
	SElemType elem;

	init_stack(&operator_stack);
	ch = '#';
	push(&operator_stack, &ch);
	printf("\nEnter an arithmetic expression:\n");
	ch = getchar();
	while (ch != '#')
	{
		switch (ch)
		{
		case '+':
		case '-':
			get_top(&operator_stack, &elem);
			while (elem != '(' && elem != '#')
			{
				pop(&operator_stack, &elem);
				push(result_stack, &elem);
				get_top(&operator_stack, &elem);
			}
			push(&operator_stack, &ch);
			ch = getchar();
			break;
		case '*':
		case '/':
			get_top(&operator_stack, &elem);
			while (elem == '*' || elem == '/')
			{
				pop(&operator_stack, &elem);
				push(result_stack, &elem);
				get_top(&operator_stack, &elem);
			}
			push(&operator_stack, &ch);
			ch = getchar();
			break;
		case '(':
			push(&operator_stack, &ch);
			ch = getchar();
			break;
		case ')':
			get_top(&operator_stack, &elem);
			while (elem != '(')
			{
				pop(&operator_stack, &elem);
				push(result_stack, &elem);
				get_top(&operator_stack, &elem);
			}
			pop(&operator_stack, &elem);
			ch = getchar();
			break;
		default:
			if (ch >= '0' && ch <= '9')
			{
				push(result_stack, &ch);
			}
			ch = getchar();
			break;
		}
		//print_stack(&operator_stack);
		//print_stack(result_stack);
	}
	// Now we have finished scanning the expression
	//printf("\n==finish scanning===\n");
	get_top(&operator_stack, &elem);
	while (elem != '#')
	{
		pop(&operator_stack, &elem);
		push(result_stack, &elem);
		get_top(&operator_stack, &elem);

		//print_stack(&operator_stack);
		//print_stack(result_stack);
	}
	//printf("\n=====final======");
	//print_stack(&operator_stack);
	//print_stack(result_stack);
	destroy_stack(&operator_stack);
}

void calculate_reverse_polish_notation(Stack* rpn_stack, int* result)
{
	int calculate(int operand_1, char op, int operand_2);

	Stack s, result_stack;
	SElemType elem, elem1, elem2;

	init_stack(&s);
	init_stack(&result_stack);
	while (is_empty(rpn_stack) == 0)
	{
		pop(rpn_stack, &elem);
		push(&s, &elem);
	}
	while (is_empty(&s) == 0)
	{
		pop(&s, &elem);
		push(rpn_stack, &elem);
		switch (elem)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			pop(&result_stack, &elem2);
			pop(&result_stack, &elem1);
			elem1 = calculate(elem1, elem, elem2);
			push(&result_stack, &elem1);
			break;
		default:
			elem = elem - '0';
			push(&result_stack, &elem);
			break;
		}
	}
	pop(&result_stack, result);
	destroy_stack(&s);
	destroy_stack(&result_stack);
}

int calculate(int operand_1, char op, int operand_2)
{
	switch (op)
	{
	case '+':
		return operand_1 + operand_2;
		break;
	case '-':
		return operand_1 - operand_2;
		break;
	case '*':
		return operand_1 * operand_2;
		break;
	case '/':
		if (operand_2 == 0)
		{
			printf("\nError: the divisor is zero!!!");
			exit(INFEASIBLE);
		}
		return operand_1 / operand_2;
		break;
	default:
		printf("\nError: illegal operator!!!");
		exit(INFEASIBLE);
		break;
	}
}