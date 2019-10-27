#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

// how many pop sequences
int total_pop_sequence;

void count_pop_sequence(int in_stack, int remained, int popped, int total_elements)
{
	//in_stack: how many elements are in the stack
	//remained: how many elements are remained to push
	//poped: how many elements have been poped, when poped==TOTAL_ELEMENTS, a
	// sequence is formed
	if (popped == total_elements)
	{
		total_pop_sequence++;
		return;
	}
	if (in_stack > 0)
		count_pop_sequence(in_stack - 1, remained, popped + 1, total_elements);
	if (remained > 0)
		count_pop_sequence(in_stack + 1, remained - 1, popped, total_elements);
}