/*
	there are n elements in the push_sequence,
	Ask: how many pop_sequences are there when using a stack ?
*/
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "pop_sequence.h"

extern int total_pop_sequence;

int main()
{
	int i;

	for (i = 1; i < 15; i++)
	{
		total_pop_sequence = 0;
		count_pop_sequence(0, i, 0, i);
		printf("%d : %d\n", i, total_pop_sequence);
	}

	return 0;
}