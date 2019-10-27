#include<stdio.h>
#include<stdlib.h>
#include "sequential_queue.h"

int main()
{
	SqQueue queue;
	QDataType data;
	char flag;

	init_queue(&queue);
	do
	{
		printf("\nenter(e) or delete(d):");
		scanf_s("%c", &flag, 1);
		if (flag == 'e')
		{
			printf("\nEnter an integer:");
			scanf_s("%d", &data);
			en_queue(&queue, data);
		}
		else
		{
			de_queue(&queue, &data);
			printf("\nThe deleted integer: %d", data);
		}
		print_queue(&queue);
		printf("\nContinue?(y/n):");
		while (getchar() != '\n');
		scanf_s("%c", &flag, 1);
		while (getchar() != '\n');
	} while (flag=='Y' || flag=='y');

	destroy_queue(&queue);

	return 0;
}