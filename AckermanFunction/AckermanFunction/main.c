#include<stdio.h>
#include<stdlib.h>
#include "ackerman.h"

int main()
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("\nack(%d, %d) = %d  %d", i, j, ack_recursive(i, j), ack_not_recursive(i, j));
		}
	}
	
	return 0;
}