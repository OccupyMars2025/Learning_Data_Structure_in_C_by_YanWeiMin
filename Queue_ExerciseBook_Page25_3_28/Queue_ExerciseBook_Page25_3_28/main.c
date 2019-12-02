#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

int main()
{
	Queue queue;
	int flag;
	QElemType data;

	init_queue(&queue);
	do
	{
		printf("\nenter(0) or delete(1):");
		scanf_s("%d", &flag);
		if (flag == 0)
		{
			printf("\nEnter an integer:");
			scanf_s("%d", &data);
			en_queue(&queue, &data);
		}
		else if (flag == 1)
		{
			de_queue(&queue, &data);
			printf("\nThe deleted element: %d", data);
		}
		print_queue(&queue);
		printf("\nContinue?(y/n):");
		while (getchar() != '\n');
		flag = getchar();
	} while (flag == 'y');
	destroy_queue(&queue);

	return 0;
}