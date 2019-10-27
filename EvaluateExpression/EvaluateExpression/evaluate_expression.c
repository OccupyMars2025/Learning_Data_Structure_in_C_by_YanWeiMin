#include "my_stack.h"
#include<stdio.h>
#include<stdlib.h>

char compare_priority(char operator_1, char operator_2)
{
	switch (operator_2)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '#':
		break;
	default:
		printf("\ninvalid operator!!!");
		exit(1);
		break;
	}

	//operator: + - * / ( ) #
	switch (operator_1)
	{
	case '+':
	case '-':
		// '>': + - ) #
		// '<': * / (
		if (operator_2 == '*' || operator_2 == '/' || operator_2 == '(')
			return '<';
		else
			return '>';
		break;
	case '*':
	case '/':
		// '<': (
		// '>': + - * / ) #
		if (operator_2 == '(')
			return '<';
		else
			return '>';
		break;
	case '(':
		// '<': + - * / (
		// '=': )
		// '?': #
		if (operator_2 == ')')
			return '=';
		else if (operator_2 == '#')
		{
			printf("\ninvalid expression!!!");
			exit(1);
		}
		else
			return '<';
		break;
	case ')':
		// '>': + - * / ) #
		// '?': (
		if (operator_2 == '(')
		{
			printf("\ninvalid expression!!!");
			exit(1);
		}
		else
			return '>';
		break;
	case '#':
		// '<': + - * / ( 
		// '?': )
		// '=': #
		if (operator_2 == ')')
		{
			printf("\ninvalid expression!!!");
			exit(1);
		}
		else if (operator_2 == '#')
			return '=';
		else
			return '<';
		break;
	default:
		printf("\ninvalid operator!!!");
		exit(1);
		break;
	}
}

int is_operator(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '#':
		return 1;
		break;
	default:
		return 0;
		break;
	}
}

int calculate(int operand_1, char operator_, int operand_2)
{
	switch (operator_)
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
		return operand_1 / operand_2;
		break;
	default:
		printf("\ninvalid operator!!!");
		exit(1);
		break;
	}
}

void evaluate_expression()
{
	char compare_priority(char operator_1, char operator_2);
	int is_operator(char ch);
	int calculate(int operand_1, char operator_, int operand_2);

	Stack operand_stack, operator_stack;
	SElemType elem, operand_1, operand_2, result;
	char ch;

	printf("\nEnter an expression:\n");
	init_stack(&operand_stack);
	init_stack(&operator_stack);
	push(&operator_stack, '#');
	ch = getchar();
	get_top(&operator_stack, &elem);
	while (ch != '#' || elem != '#')
	{
		if (is_operator(ch) == 0)
		{
			push(&operand_stack, ch-'0');
			ch = getchar();
			continue;
		}
		switch (compare_priority(elem, ch))
		{
		case '<':
			push(&operator_stack, ch);
			elem = ch;
			ch = getchar();
			break;
		case '>':
			pop(&operator_stack, &elem);
			pop(&operand_stack, &operand_2);
			pop(&operand_stack, &operand_1);
			push(&operand_stack, calculate(operand_1, elem, operand_2));
			get_top(&operator_stack, &elem);
			break;
		case '=':
			pop(&operator_stack, &elem);
			get_top(&operator_stack, &elem);
			ch = getchar();
			break;
		default:
			printf("\ninvalid expression or invalid operator!!!");
			exit(1);
			break;
		}
	}
	get_top(&operand_stack, &result);
	printf("\n\nfinal result: %d", result);
}