#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "reverse_polish_notation.h"

int main()
{
	Stack rpn_stack;
	int result;

	init_stack(&rpn_stack);
	get_reverse_polish_notation(&rpn_stack);
	printf("\nReverse Polish Notation:\n");
	print_stack(&rpn_stack);

	calculate_reverse_polish_notation(&rpn_stack, &result);
	printf("\nresult: %d", result);
	printf("\nNow, Reverse Polish Notation:\n");
	print_stack(&rpn_stack);

	destroy_stack(&rpn_stack);

	return 0;
}