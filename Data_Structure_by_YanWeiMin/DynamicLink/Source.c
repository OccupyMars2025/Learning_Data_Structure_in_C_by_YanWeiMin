#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define OK 2
#define ERROR 3
#define OVERFLOW 4
#define INFEASIBLE 5

typedef int Status;
typedef int ElemType;
typedef struct Node_0
{
	ElemType data;
	struct Node_0* next;
} Node, *LinkList;

int main()
{
	Status create_list(LinkList * list, int count);
	void print_list(LinkList list);
	Status get_elem(LinkList list, int position, ElemType * data);

	LinkList list;
	int count, position;
	ElemType data;
	
	printf("\nHow many elements:");
	scanf_s("%d", &count);
	create_list(&list, count);
	print_list(list);

	return 0;
}

Status create_list(LinkList* list, int count)
{
	int i;
	Node* p, * q;

	*list = (Node*)malloc(sizeof(Node));
	if (*list == NULL)
		exit(OVERFLOW);
	q = *list;
	printf("\nEnter %d elements:\n", count);
	for (i = 0; i < count; ++i)
	{
		p = (Node*)malloc(sizeof(Node));
		if (p == NULL)
			exit(OVERFLOW);
		scanf_s("%d", &(p->data));
		q->next = p;
		q = p;
	}
	q->next = NULL;

	return OK;
}

void print_list(LinkList list)
{
	Node* p = list->next;

	printf("\n=====the list=====\n");
	while (p != NULL)
	{
		printf("%d, ", p->data);
		p = p->next;
	}
}

Status get_elem(LinkList list, int position, ElemType* data)
{
	Node* p = list->next;
	int i = 1;

	while (i < position && p != NULL)
	{
		++i;
		p = p->next;
	}
	if (i == position && p != NULL)
	{
		*data = p->data;
		return OK;
	}
	else
	{
		*data = 0;
		return ERROR;
	}
}