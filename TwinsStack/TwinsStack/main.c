#include<stdio.h>
#include<stdlib.h>
#include "twins_stack.h"

int main()
{
	Twins_Stack ts;
	SDataType data;
	char flag;
	int which_stack, which_operation;

	init_stack(&ts);
	do
	{
		printf("\nstack 0 or stack 1: ");
		scanf_s("%d", &which_stack);
		printf("\npush(1) or pop(0): ");
		scanf_s("%d", &which_operation);
		switch (which_operation)
		{
		case 1:
			printf("\nEnter an integer:");
			scanf_s("%d", &data);
			push(&ts, which_stack, data);
			break;
		case 0:
			pop(&ts, which_stack, &data);
			printf("\nThe poped integer: %d", data);
			break;
		default:
			printf("\nError: choose operation: push(1) or pop(0)");
			exit(INFEASIBLE);
			break;
		}
		print_stack(&ts, 0);
		print_stack(&ts, 1);
		printf("\nContinue?(y/n):");
		while (getchar() != '\n');
		scanf_s("%c", &flag, 1);
	} while (flag=='y');

	return 0;
}