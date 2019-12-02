#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

void init_queue(Queue* queue)
{
	queue->base = (QElemType*)malloc(MAX_QUEUE_SPACE * sizeof(QElemType));
	if (queue->base == NULL)
	{
		printf("\nmalloc failure !!!");
		exit(OVERFLOW);
	}
	queue->front = queue->rear = queue->tag = 0;
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
	if (queue->front == queue->tag && queue->tag == 1)
	{
		printf("\nError: full queue!!!");
		exit(INFEASIBLE);
	}
	queue->tag = 1;
	queue->base[queue->rear] = *elem;
	queue->rear = (queue->rear + 1) % MAX_QUEUE_SPACE;
}

void de_queue(Queue* queue, QElemType* elem)
{
	if (queue->front == queue->tag && queue->tag == 0)
	{
		printf("\nError: empty queue!!!");
		exit(INFEASIBLE);
	}
	queue->tag = 0;
	*elem = queue->base[queue->front];
	queue->front = (queue->front + 1) % MAX_QUEUE_SPACE;
}

void sum_queue(Queue* queue, int* result)
{
	int is_empty(Queue * queue);
	int i;

	if (is_empty(queue) == 1)
	{
		printf("\nError: empty queue!!!");
		exit(INFEASIBLE);
	}
	i = queue->front;
	*result = queue->base[i];
	i = (i + 1) % MAX_QUEUE_SPACE;
	while (i != queue->rear)
	{
		*result += queue->base[i];
		i = (i + 1) % MAX_QUEUE_SPACE;
	}
}

void print_fibonacci(int upper_bound)
{
	void sum_queue(Queue * queue, int* result);

	Queue queue;
	QElemType elem;
	int i, result;

	init_queue(&queue);
	printf("\nAll Fibonacci numbers that are <= %d:\n", upper_bound);
	elem = 0;
	for (i = 1; i <= K - 2; i++)
	{
		printf("%d, ", elem);
		en_queue(&queue, &elem);
	}
	elem = 1;
	for (i = 1; i <= 2; i++)
	{
		printf("%d, ", elem);
		en_queue(&queue, &elem);
	}
	
	sum_queue(&queue, &result);
	while (result <= upper_bound)
	{
		printf("%d, ", result);
		de_queue(&queue, &elem);
		elem = result;
		en_queue(&queue, &elem);
		sum_queue(&queue, &result);
	}

	destroy_queue(&queue);

	printf("\n\n");
}