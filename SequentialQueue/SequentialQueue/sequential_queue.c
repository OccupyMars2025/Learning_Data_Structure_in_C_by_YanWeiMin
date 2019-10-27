#include<stdio.h>
#include<stdlib.h>
#include "sequential_queue.h"

void init_queue(SqQueue* queue)
{
	queue->base = (QDataType*)malloc(MAX_QUEUE_SPACE * sizeof(QDataType));
	if (queue->base == NULL)
	{
		printf("\nmalloc failure!!!");
		exit(OVERFLOW);
	}
	queue->front = queue->rear = 0;
}

int is_empty(SqQueue* queue)
{
	if (queue->front == queue->rear)
		return 1;
	else
		return 0;
}

int is_full(SqQueue* queue)
{
	if ((queue->rear + 1) % MAX_QUEUE_SPACE == queue->front)
		return 1;
	else
		return 0;
}

int queue_length(SqQueue* queue)
{
	return (queue->rear - queue->front + MAX_QUEUE_SPACE) % MAX_QUEUE_SPACE;
}

void destroy_queue(SqQueue* queue)
{
	free(queue->base);
}

void en_queue(SqQueue* queue, QDataType data)
{
	if ((queue->rear + 1) % MAX_QUEUE_SPACE == queue->front)
	{
		printf("\nfull queue!!!");
		exit(INFEASIBLE);
	}
	queue->base[queue->rear] = data;
	queue->rear = (queue->rear + 1) % MAX_QUEUE_SPACE;
}

void de_queue(SqQueue* queue, QDataType* data)
{
	if (queue->front == queue->rear)
	{
		printf("\nempty queue!!!");
		exit(INFEASIBLE);
	}
	*data = queue->base[queue->front];
	queue->front = (queue->front + 1) % MAX_QUEUE_SPACE;
}

void print_queue(SqQueue* queue)
{
	int i = queue->front;

	printf("\n===the queue=====\n");
	while (i != queue->rear)
	{
		printf("%d, ", queue->base[i]);
		i = (i + 1) % MAX_QUEUE_SPACE;
	}
	printf("\n");
}
