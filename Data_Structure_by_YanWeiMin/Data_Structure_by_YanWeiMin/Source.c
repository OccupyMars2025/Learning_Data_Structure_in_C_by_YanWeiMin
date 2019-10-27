#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define OK 2
#define ERROR 3
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INITIAL_SIZE 2
#define LIST_INCREMENT 2

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;

int main()
{
	int compare(ElemType e1, ElemType e2);
	Status list_init(SqList * list);
	Status list_insert(SqList * list, int position, ElemType e);
	Status list_print(SqList * list);
	Status list_delete(SqList * list, int position, ElemType * e);
	Status list_locate(SqList * list, int* position, ElemType e,
		int (*compare)(ElemType, ElemType));
	Status list_merge(SqList * list_1, SqList * list_2, SqList * merged_list);

	SqList list, list_2, merged_list;
	int n, i;
	ElemType e;
	int position;

	list_init(&list);
	printf("\nHow many elements:");
	scanf_s("%d", &n);
	printf("\nEnter %d elements:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &e);
		list_insert(&list, 1, e);
	}
	printf("\nThe list is:\n");
	list_print(&list);

	printf("\nEnter the element to locate:");
	scanf_s("%d", &e);
	list_locate(&list, &position, e, compare);
	printf("\nThe position of the element %d is: %d", e, position);
	list_print(&list);

	printf("\nEnter the position of the element that you want to delete:");
	scanf_s("%d", &position);
	list_delete(&list, position, &e);
	printf("\nThe deleted element: %d", e);
	list_print(&list);

	printf("\nEnter the position of the element that you want to delete:");
	scanf_s("%d", &position);
	list_delete(&list, position, &e);
	printf("\nThe deleted element: %d", e);
	list_print(&list);

	printf("\nEnter the position of the element that you want to delete:");
	scanf_s("%d", &position);
	list_delete(&list, position, &e);
	printf("\nThe deleted element: %d", e);
	list_print(&list);

	list_init(&list_2);
	printf("\nHow many elements in list_2:");
	scanf_s("%d", &n);
	printf("\nEnter %d elements:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &e);
		list_insert(&list_2, 1, e);
	}
	printf("\nThe list_2 is:\n");
	list_print(&list_2);

	list_merge(&list, &list_2, &merged_list);
	printf("\nThe merged list:");
	list_print(&merged_list);

	return 0;
}

// modify this function when ElemType is changed
int compare(ElemType e1, ElemType e2) 
{
	return e1 - e2;
}

Status list_init(SqList* list)
{
	list->elem = (ElemType*)malloc(LIST_INITIAL_SIZE * sizeof(ElemType));
	if (!list->elem)
		exit(OVERFLOW);
	list->length = 0;
	list->listsize = LIST_INITIAL_SIZE;

	return OK;
}

Status list_insert(SqList* list, int position, ElemType e)
{
	ElemType* p, *q, * new_base;

	if (position<1 || position>list->length + 1)
		return ERROR;
	if (list->length >= list->listsize){
		new_base = (ElemType*)realloc(list->elem, (list->listsize + LIST_INCREMENT) * sizeof(ElemType));
		if (new_base == NULL)
			exit(OVERFLOW);
		list->elem = new_base;
		list->listsize += LIST_INCREMENT;
	}
	q = list->elem + position - 1;
	for (p = list->elem + list->length - 1; p >= q; p--) {
		*(p + 1) = *p;
	}
	*q = e;
	list->length++;

	return OK;
}

Status list_print(SqList* list)
{
	ElemType* p, * p_end;
	
	p_end = list->elem + list->length - 1;
	printf("\n");
	for (p = list->elem; p <= p_end; ++p)
	{
		printf("%d, ", *p);
	}
	printf("\n");

	return OK;
}

Status list_delete(SqList* list, int position, ElemType* e) 
{
	ElemType* p, * q;

	if (position<1 || position>list->length)
		return ERROR;
	p = list->elem + position - 1;
	*e = *p;
	q = list->elem + list->length;
	for (++p; p < q; p++) {
		*(p - 1) = *p;
	}
	--list->length;

	return OK;
}

Status list_locate(SqList* list, int* position, ElemType e, 
			int (*compare)(ElemType, ElemType)) 
{
	ElemType* p, * start, * end;

	start = list->elem;
	end = list->elem + list->length - 1;
	for (p = start; p <= end; ++p) {
		if ((*compare)(*p, e) == 0) {
			*position = p - start + 1;
			return OK;
		}
	}
	*position = -1;

	return OK;
}

//assume list_1 and list_2 are all non-decreasing
// the merged_list must be non-decreasing
Status list_merge(SqList* list_1, SqList* list_2, SqList* merged_list) 
{
	ElemType* p1, * p2, * p, * p1_end, * p2_end;

	merged_list->length = merged_list->listsize = list_1->length + list_2->length;
	merged_list->elem = (ElemType*)malloc(merged_list->listsize * sizeof(ElemType));
	if (merged_list->elem == NULL)
		exit(OVERFLOW);
	
	p = merged_list->elem;
	p1 = list_1->elem;  p2 = list_2->elem;
	p1_end = list_1->elem + list_1->length - 1;
	p2_end = list_2->elem + list_2->length - 1;
	while (p1 <= p1_end && p2 <= p2_end)
	{
		if (compare(*p1, *p2) < 0) {
			*p++ = *p1++;
		}
		else
		{
			*p++ = *p2++;
		}
	}
	while (p1 <= p1_end)
	{
		*p++ = *p1++;
	}
	while (p2 <= p2_end)
	{
		*p++ = *p2++;
	}

	return OK;
}

