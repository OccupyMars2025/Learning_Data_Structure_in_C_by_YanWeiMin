#include<stdio.h>
#include<stdlib.h>
#include "my_function.h"

int main()
{
	LinkList L, L2;

	CreateList1(&L);
	PrintList(&L);
	CreateList2(&L2);
	PrintList(&L2);

	return 0;
}

LNode* GetNode(LinkList L, int position)
{
	if (position < 1)
	{
		printf("\nError: invalid parameters!!!");
		exit(1);
	}
	int i;
	LNode* node;
	// to be continued...
}
void CreateList2(LinkList* L)
{
	// wei cha fa
	(*L) = (LNode*)malloc(sizeof(LNode));
	if ((*L) == NULL)
	{
		printf("\nError: malloc failure!!!");
		exit(1);
	}
	LNode* node, * rear;
	int i, n;
	ElemType data;

	printf("\nHow many integers: ");
	scanf_s("%d", &n);
	if (n < 1)
	{
		printf("\nError: invalid input!!!");
		exit(1);
	}
	printf("\nEnter %d integers:\n", n);
	rear = *L;
	for (i = 1; i <= n; ++i)
	{
		node = (LNode*)malloc(sizeof(LNode));
		if (node == NULL)
		{
			printf("\nError: malloc failure!!!");
			exit(1);
		}
		scanf_s("%d", &data);
		node->data = data;
		rear->next = node;
		rear = node;
	}
	rear->next = NULL;
}

void CreateList1(LinkList* L)
{
	LNode* node;
	ElemType x;
	int i, n;

	*L = (LNode*)malloc(sizeof(LNode));
	if (*L == NULL)
	{
		printf("\nError: malloc failure!!!");
		exit(1);
	}
	(*L)->next = NULL;
	printf("\nHow many integers: ");
	scanf_s("%d", &n);
	if (n < 1)
	{
		printf("\nError: invalid input!!!");
		exit(1);
	}
	printf("\nEnter %d integers:\n", n);
	for (i = 1; i <= n; ++i)
	{
		scanf_s("%d", &x);
		node = (LNode*)malloc(sizeof(LNode));
		if (node == NULL)
		{
			printf("\nError: malloc failure!!!");
			exit(1);
		}
		node->data = x;
		node->next = (*L)->next;
		(*L)->next = node;
	}
}

void PrintList(LinkList* L)
{
	LNode* node;

	printf("\n\n=====the list======\n");
	node = (*L)->next;
	while (node != NULL)
	{
		printf("%d, ", node->data);
		node = node->next;
	}
}