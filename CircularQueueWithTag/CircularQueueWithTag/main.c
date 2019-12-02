#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

int main()
{
	Queue queue;
	int flag;
	char flag2;
	QElemType elem;

	init_queue(&queue);
	do
	{
		printf("\nenter(1) or delete(0):");
		scanf_s("%d", &flag);
		if (flag == 1)
		{
			printf("\nEnter an integer:");
			scanf_s("%d", &elem);
			en_queue(&queue, &elem);
		}
		else if (flag == 0)
		{
			de_queue(&queue, &elem);
			printf("\nThe deleted integer: %d", elem);
		}
		print_queue(&queue);
		printf("\nfull: %d, empty: %d", is_full(&queue), is_empty(&queue));
		printf("\nContinue?(y/n):");
		while (getchar() != '\n');
		scanf_s("%c", &flag2, 1);
	} while (flag2 == 'y');
	destroy_queue(&queue);

	return 0;
}