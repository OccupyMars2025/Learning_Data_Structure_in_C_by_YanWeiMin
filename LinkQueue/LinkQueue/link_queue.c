#include "link_queue.h"
#include<stdio.h>
#include<stdlib.h>

void init_queue(LinkQueue* queue)
{
	queue->front = (QNode*)malloc(sizeof(QNode));
	if (queue->front == NULL)
	{
		printf("\nmalloc failure!!!");
		exit(1);
	}
	queue->rear = queue->front;
	queue->front->next = NULL;
}

void destroy_queue(LinkQueue* queue)
{
	QNode* p = queue->front, *q;

	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
}

void en_queue(LinkQueue* queue, QDataType data)
{
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (p == NULL)
	{
		printf("\nmalloc failure!!!");
		exit(1);
	}
	p->data = data; p->next = NULL;
	queue->rear->next = p;
	queue->rear = p;
}

int is_empty(LinkQueue* queue)
{
	if (queue->front == queue->rear)
		return 1;
	else
		return 0;
}

void de_queue(LinkQueue* queue, QDataType* data)
{
	QNode* p;

	if (queue->front == queue->rear)
	{
		printf("\nempty queue!!!");
		exit(1);
	}
	p = queue->front->next;
	*data = p->data;
	queue->front->next = p->next;
	if (queue->rear == p)
		queue->rear = queue->front;
	free(p);
}

void print_queue(LinkQueue* queue)
{
	QNode* p = queue->front->next;

	printf("\n");
	while (p != NULL)
	{
		printf("%d, ", p->data);
		p = p->next;
	}
	printf("\n");
}