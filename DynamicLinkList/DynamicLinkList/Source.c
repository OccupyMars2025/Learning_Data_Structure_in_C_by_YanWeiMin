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
} Node, * LinkList;

int main()
{
	Status create_list(LinkList * list, int count);
	void print_list(LinkList list);
	Status get_elem(LinkList list, int position, ElemType * data);
	Status insert_elem(LinkList list, int position, ElemType data);
	Status delete_elem(LinkList list, int position, ElemType * data);
	void merge_list(LinkList list_1, LinkList list_2, LinkList* merged_list);

	LinkList list, list_2, merged_list;
	int count, position, flag;
	ElemType data;

	printf("\nHow many elements:");
	scanf_s("%d", &count);
	create_list(&list, count);
	print_list(list);

	do {
		printf("\nEnter the position:");
		scanf_s("%d", &position);
		get_elem(list, position, &data);
		printf("\nThe element at the position %d : %d", position, data);
		printf("\nContinue?(y/n):");
		while (getchar() != '\n');
		flag = getchar();
	} while (flag=='y' || flag=='Y');

	do {
		printf("\nEnter position,element that you want to insert:");
		scanf_s("%d%d", &position, &data);
		insert_elem(list, position, data);
		print_list(list);
		printf("\nContinue?(y/n):");
		while (getchar() != '\n');
		flag = getchar();
	} while (flag == 'y' || flag == 'Y');

	do {
		printf("\nEnter the position:");
		scanf_s("%d", &position);
		delete_elem(list, position, &data);
		printf("\nDeleted element: %d", data);
		print_list(list);
		printf("\nContinue?(y/n):");
		while (getchar() != '\n');
		flag = getchar();
	} while (flag == 'y' || flag == 'Y');

	printf("\nHow many elements in list_2:");
	scanf_s("%d", &count);
	create_list(&list_2, count);
	print_list(list_2);

	merge_list(list, list_2, &merged_list);
	printf("\nMerge the 2 lists:\n");
	print_list(merged_list);

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

Status insert_elem(LinkList list, int position, ElemType data)
{
	int i = 1;
	Node* p = list, *pnew;

	while (i < position && p != NULL)
	{
		i++;
		p = p->next;
	}
	if (i == position && p != NULL)
	{
		pnew = (Node*)malloc(sizeof(Node));
		if (pnew == NULL)
			exit(OVERFLOW);
		pnew->data = data;
		pnew->next = p->next;
		p->next = pnew;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

Status delete_elem(LinkList list, int position, ElemType* data)
{
	int i = 1;
	Node* p = list, * pdeleted;

	while (i < position && p != NULL)
	{
		i++;
		p = p->next;
	}
	if (i == position && p != NULL && p->next != NULL)
	{
		pdeleted = p->next;
		*data = pdeleted->data;
		p->next = pdeleted->next;
		free(pdeleted);
		return OK;
	}
	else
	{
		*data = 0;
		return ERROR;
	}
}

void merge_list(LinkList list_1, LinkList list_2, LinkList *merged_list)
{
	// all 3 lists must be non-decreasing
	Node* p1, * p2, * pmerged;

	p1 = list_1->next; 
	p2 = list_2->next;
	pmerged = *merged_list = list_1;
	while (p1 && p2 )
	{
		if (p1->data < p2->data)
		{
			pmerged->next = p1;
			pmerged = p1;
			p1 = p1->next;
		}
		else
		{
			pmerged->next = p2;
			pmerged = p2;
			p2 = p2->next;
		}
	}
	pmerged->next = p1 ? p1 : p2;
	free(list_2);
}