#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define OVERFLOW 2
#define ERROR 3
#define INFEASIBLE 4
#define OK 5

#define MAXCOUNT 1000

typedef int Status;
typedef int ElemType;
typedef struct{
	ElemType data;
	int cursor;
} Node, SLinkList[MAXCOUNT];

int main() {
	void create_list(SLinkList * list, int count);
	void print_list(SLinkList* list);
	void insert_element(SLinkList * list, int position, ElemType data);
	void delete_element(SLinkList * list, int position, ElemType * data);
	int locate_elem(SLinkList * list, ElemType data);
	void difference(SLinkList * space, int* head);

	SLinkList list;
	int count, position, flag, head;
	ElemType data;

	printf("\nHow many elements:");
	scanf_s("%d", &count);
	create_list(&list, count);
	print_list(&list);

	do {
		printf("\nEnter position,element to insert:");
		scanf_s("%d%d", &position, &data);
		insert_element(&list, position, data);
		print_list(&list);
		printf("\nContinue?(y/n):");
		while (getchar() != '\n');
		flag = getchar();
	} while (flag == 'y' || flag == 'Y');

	do {
		printf("\nEnter the position (delete):");
		scanf_s("%d", &position);
		delete_element(&list, position, &data);
		printf("\nThe deleted element:%d", data);
		print_list(&list);
		printf("\nContinue?(y/n):");
		while (getchar() != '\n');
		flag = getchar();
	} while (flag == 'y' || flag == 'Y');

	do {
		printf("\nEnter the element to locate:");
		scanf_s("%d", &data);
		position = locate_elem(&list, data);
		printf("\nThe position of the element %d: %d", data, position);
		printf("\nContinue?(y/n):");
		while (getchar() != '\n');
		flag = getchar();
	} while (flag == 'y' || flag == 'Y');

	difference(&list, &head);

	return 0;
}

void create_list(SLinkList* list, int count)
{
	void init_list(SLinkList * list);
	void insert_element(SLinkList * list, int position, ElemType data);

	int i;
	ElemType data;
	init_list(list);
	printf("\nEnter %d elements:\n", count);
	for (i = 0; i < count; i++)
	{
		scanf_s("%d", &data);
		insert_element(list, 1, data);
	}
}

void init_list(SLinkList* list) {
	int i;

	(*list)[0].cursor = 2;
	(*list)[1].cursor = 1;
	for (i = 2; i < MAXCOUNT - 1; i++) {
		(*list)[i].cursor = i + 1;
	}
	(*list)[MAXCOUNT - 1].cursor = 0;
}

void print_list(SLinkList* list) {
	int i;

	printf("\n====the list========\n");
	for (i = (*list)[1].cursor; i != 1; i = (*list)[i].cursor) {
		printf("%d, ", (*list)[i].data);
	}
	printf("\n");
}

int alloc_space(SLinkList* list)
{
	int i;

	if ((*list)[0].cursor == 0)
	{
		printf("not enough space!!!\n");
		exit(OVERFLOW);
	}
	i = (*list)[0].cursor;
	(*list)[0].cursor = (*list)[i].cursor;

	return i;
}

void free_space(SLinkList* list, int position)
{
	(*list)[position].cursor = (*list)[0].cursor;
	(*list)[0].cursor = position;
}

void insert_element(SLinkList* list, int position, ElemType data) 
{
	int alloc_space(SLinkList * list);

	int i = 1;
	int current_cursor = 1;
	int next_cursor;
	int inserted;

	while (i < position && (next_cursor=(*list)[current_cursor].cursor) != 1)
	{
		i++;
		current_cursor = next_cursor;
	}
	if (i == position) {
		inserted = alloc_space(list);
		(*list)[inserted].data = data;
		(*list)[inserted].cursor = (*list)[current_cursor].cursor;
		(*list)[current_cursor].cursor = inserted;
	}
}

void delete_element(SLinkList* list, int position, ElemType* data)
{
	void free_space(SLinkList * list, int position);

	int i = 1;
	int current_cursor = 1;
	int next_cursor;
	int deleted;

	while (i < position && (next_cursor=(*list)[current_cursor].cursor) != 1)
	{
		i++;
		current_cursor = next_cursor;
	}
	if (i == position && (*list)[current_cursor].cursor != 1)
	{
		deleted = (*list)[current_cursor].cursor;
		(*list)[current_cursor].cursor = (*list)[deleted].cursor;
		*data = (*list)[deleted].data;
		free_space(list, deleted);
	}
	else
	{
		*data = 0;
	}
}

int locate_elem(SLinkList* list, ElemType data)
{
	int i = (*list)[1].cursor;
	int position = 1;

	while (i != 1)
	{
		if ((*list)[i].data == data)
			break;
		i = (*list)[i].cursor;
		position++;
	}

	if (i == 1)
		return -1;
	else
		return position;
}

int get_elem_cursor(SLinkList* list, ElemType data)
{
	int i = (*list)[1].cursor;

	while (i != 1)
	{
		if ((*list)[i].data == data)
			break;
		i = (*list)[i].cursor;
	}
	
	return (i != 1) ? i : -1;
}

void print_list_002(SLinkList* space, int head)
{
	int i = (*space)[head].cursor;

	printf("\n=====the list=======\n");
	while (i != 0)
	{
		printf("%d, ", (*space)[i].data);
		i = (*space)[i].cursor;
	}
	printf("\n");
}

void add_different_delete_same(SLinkList* space, int head, ElemType data)
{
	int alloc_space(SLinkList * list);
	void free_space(SLinkList * list, int cursor);

	int i = head;
	int j = (*space)[head].cursor;
	int k;

	while (j != 0)
	{
		if ((*space)[j].data == data)
		{
			(*space)[i].cursor = (*space)[j].cursor;
			free_space(space, j);
			return;
		}
		i = j;
		j = (*space)[j].cursor;
	}
	k = alloc_space(space);
	(*space)[k].data = data;
	(*space)[k].cursor = 0;
	(*space)[i].cursor = k;
}

void difference(SLinkList* space, int* head)
{
	int alloc_space(SLinkList * list);
	void print_list_002(SLinkList * space, int head);
	void add_different_delete_same(SLinkList * space, int head, ElemType data);

	int i, count, cursor;
	ElemType data;

	for (i = 0; i < MAXCOUNT - 1; i++)
	{
		(*space)[i].cursor = i + 1;
	}
	(*space)[MAXCOUNT - 1].cursor = 0;

	printf("\nHow many elements in list A:");
	scanf_s("%d", &count);
	printf("\nEnter %d elements:\n", count);
	*head = alloc_space(space);
	(*space)[*head].cursor = 0;
	for (i = 0; i < count; i++)
	{
		cursor = alloc_space(space);
		scanf_s("%d", &data);
		(*space)[cursor].data = data;
		(*space)[cursor].cursor = (*space)[*head].cursor;
		(*space)[*head].cursor = cursor;
	}
	print_list_002(space, *head);

	printf("\nHow many elements in list B:");
	scanf_s("%d", &count);
	for (i = 0; i < count; i++)
	{
		scanf_s("%d", &data);
		add_different_delete_same(space, *head, data);
	}
	printf("\n(A-B)U(B-A):\n");
	print_list_002(space, *head);
}



