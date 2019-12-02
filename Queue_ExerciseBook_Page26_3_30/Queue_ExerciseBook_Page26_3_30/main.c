#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

int main()
{
	int flag, flag2;
	Queue queue;
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
		printf("\nContinue?(y/n):");
		while (getchar() != '\n');
		flag2 = getchar();
	} while (flag2 == 'y');
	destroy_queue(&queue);

	return 0;
}