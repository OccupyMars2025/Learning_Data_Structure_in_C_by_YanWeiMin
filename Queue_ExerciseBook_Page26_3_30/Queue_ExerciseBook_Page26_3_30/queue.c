#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

void init_queue(Queue* queue)
{
	queue->base = (QElemType*)malloc(MAX_QUEUE_SPACE * sizeof(QElemType));
	if (queue->base == NULL)
	{
		printf("\nmalloc failure!!!");
		exit(OVERFLOW);
	}
	queue->rear = queue->length = 0;
}

void destroy_queue(Queue* queue)
{
	free(queue->base);
}

int is_empty(Queue* queue)
{
	if (queue->length == 0)
		return 1;
	else
		return 0;
}

int is_full(Queue* queue)
{
	if (queue->length == MAX_QUEUE_SPACE)
		return 1;
	else
		return 0;
}

void en_queue(Queue* queue, QElemType* elem)
{
	if (queue->length == MAX_QUEUE_SPACE)
	{
		printf("\nError: full queue!!!");
		exit(INFEASIBLE);
	}
	queue->base[queue->rear] = *elem;
	queue->rear = (queue->rear + 1) % MAX_QUEUE_SPACE;
	queue->length++;
}

void de_queue(Queue* queue, QElemType* elem)
{
	int front;

	if (queue->length == 0)
	{
		printf("\nError: empty queue!!!");
		exit(INFEASIBLE);
	}
	front = (queue->rear - queue->length + MAX_QUEUE_SPACE) % MAX_QUEUE_SPACE;
	*elem = queue->base[front];
	queue->length--;
}

void print_queue(Queue* queue)
{
	int front, len;

	front = (queue->rear - queue->length + MAX_QUEUE_SPACE) % MAX_QUEUE_SPACE;
	len = 1;
	printf("\n=====queue=========\n");
	while (len <= queue->length)
	{
		printf("%d, ", queue->base[front]);
		front = (front + 1) % MAX_QUEUE_SPACE;
		len++;
	}
	printf("\n");
}


