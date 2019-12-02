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
	queue->front = queue->rear = 0;
	queue->tag = 0;
}

void destroy_queue(Queue* queue)
{
	free(queue->base);
}

int is_empty(Queue* queue)
{
	if (queue->front == queue->rear && queue->tag == 0)
		return 1;
	else
		return 0;
}

int is_full(Queue* queue)
{
	if (queue->front == queue->rear && queue->tag == 1)
		return 1;
	else
		return 0;
}

void en_queue(Queue* queue, QElemType* elem)
{
	if (queue->front == queue->rear && queue->tag == 1)
	{
		printf("\nError: full queue!!!");
		exit(OVERFLOW);
	}
	queue->tag = 1;
	queue->base[queue->rear] = *elem;
	queue->rear = (queue->rear + 1) % MAX_QUEUE_SPACE;
}

void de_queue(Queue* queue, QElemType* elem)
{
	if (queue->front == queue->rear && queue->tag == 0)
	{
		printf("\nError: empty queue!!!");
		exit(INFEASIBLE);
	}
	queue->tag = 0;
	*elem = queue->base[queue->front];
	queue->front = (queue->front + 1) % MAX_QUEUE_SPACE;
}

void print_queue(Queue* queue)
{
	int i;

	printf("\n=====queue=========\n");
	if (queue->front == queue->rear && queue->tag == 0)
		return;
	i = queue->front;
	do
	{
		printf("%d, ", queue->base[i]);
		i = (i + 1) % MAX_QUEUE_SPACE;
	} while (i != queue->rear);
	printf("\n");
}
