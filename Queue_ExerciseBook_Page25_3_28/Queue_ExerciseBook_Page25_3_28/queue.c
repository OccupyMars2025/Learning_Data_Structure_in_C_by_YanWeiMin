#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

void init_queue(Queue* q)
{
	q->rear = (QNode*)malloc(sizeof(QNode));
	if (q->rear == NULL)
	{
		printf("\nmalloc failure!!!");
		exit(OVERFLOW);
	}
	q->rear->next = q->rear;
}

int is_empty(Queue* q)
{
	if (q->rear->next == q->rear)
		return 1;
	else
		return 0;
}

void en_queue(Queue* q, QElemType* data)
{
	QNode* new_node;
	new_node = (QNode*)malloc(sizeof(QNode));
	if (new_node == NULL)
	{
		printf("\nmalloc failure!!!");
		exit(OVERFLOW);
	}
	new_node->data = *data;
	new_node->next = q->rear->next;
	q->rear->next = new_node;
	q->rear = new_node;
}

void de_queue(Queue* q, QElemType* data)
{
	if (q->rear->next == q->rear)
	{
		printf("\nError: empty queue!!!");
		exit(INFEASIBLE);
	}
	QNode* head_node = q->rear->next;
	QNode* first_node = head_node->next;

	*data = first_node->data;
	head_node->next = first_node->next;
	if (first_node == q->rear)
		q->rear = head_node;
	free(first_node);
}

void destroy_queue(Queue* q)
{
	QNode* node1, *node2;

	node1 = q->rear->next;
	while (node1 != q->rear)
	{
		node2 = node1->next;
		free(node1);
		node1 = node2;
	}
	free(node1);
}

void print_queue(Queue* q)
{
	QNode* node;

	printf("\n====queue=====\n");
	node = q->rear->next->next;
	while (node != q->rear->next)
	{
		printf("%d, ", node->data);
		node = node->next;
	}
	printf("\n");
}