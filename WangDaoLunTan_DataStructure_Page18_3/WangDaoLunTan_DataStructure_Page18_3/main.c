#include<stdio.h>
#include<stdlib.h>
#include "my_function.h"

int main()
{
	//SqList list;

	/* page 18, 3
	init_list(&list);
	create_list(&list);
	print_list(&list);
	delete_all_x(&list, 11);
	print_list(&list);
	*/

	/* page 18, 4
	init_list(&list);
	create_list(&list);
	print_list(&list);
	delete_x_between(&list, 0, 100);
	print_list(&list);
	*/

	/* page 18, 5
	init_list(&list);
	create_list(&list);
	print_list(&list);
	delete_page18_5(&list, 10, 19);
	print_list(&list);
	*/

	/*page 18, 6
	init_list(&list);
	create_list(&list);
	print_list(&list);
	delete_page18_6(&list);
	print_list(&list);
	*/

	/*page 18, 7
	SqList list_1, list_2, merged_list;

	init_list(&list_1);
	init_list(&list_2);
	init_list(&merged_list);
	create_list(&list_1);
	print_list(&list_1);
	create_list(&list_2);
	print_list(&list_2);

	merge_page18_7(&list_1, &list_2, &merged_list);
	print_list(&merged_list);
	*/

	/* page 18, 8
	SqList A;
	int m, n;
	
	init_list(&A);
	create_list(&A);
	print_list(&A);
	printf("\nEnter m: ");
	scanf_s("%d", &m);
	printf("\nEnter n: ");
	scanf_s("%d", &n);
	exchange_page18_8(&A, m, n);
	print_list(&A);
	*/

	/* page18, 9
	SqList A;
	ElemType x;

	init_list(&A);
	create_list(&A);
	print_list(&A);
	printf("\nEnter x: ");
	scanf_s("%d", &x);
	search_page18_9(&A, x);
	print_list(&A);
	*/

	/* page 18, 10
	SqList A;
	int moves;

	init_list(&A);
	create_list(&A);
	print_list(&A);
	printf("\nEnter moves: ");
	scanf_s("%d", &moves);
	circular_move_page18_10(&A, moves);
	print_list(&A);
	*/

	/* page 18, 11
	SqList A, B;
	ElemType mid_elem, mid_elem_2;

	init_list(&A);
	init_list(&B);
	create_list(&A);
	print_list(&A);
	create_list(&B);
	print_list(&B);
	find_middle_number_page18_11(&A, &B, &mid_elem);
	printf("\n\nmiddle element: %d", mid_elem);
	find_middle_number_page18_11_method2(&A, &B, &mid_elem_2);
	printf("\n\nmiddle element (method 2): %d", mid_elem_2);
	*/

	/* page 18, 12*/
	SqList A;
	ElemType x;

	init_list(&A);
	create_list(&A);
	print_list(&A);
	find_most_occurence(&A, &x);
	printf("The most occurence: %d\n", x);

	return 0;
}

void find_most_occurence(SqList* A, ElemType* x)
{
	int i, count;
	ElemType elem;

	elem = A->base[0];
	count = 1;
	for (i = 1; i < A->length; ++i)
	{
		if (A->base[i] == elem)
			count++;
		else
		{
			if (count == 0)
			{
				elem = A->base[i];
				count = 1;
			}
			else
			{
				--count;
			}
		}
	}

	for (i = count = 0; i < A->length; ++i)
	{
		if (A->base[i] == elem)
			count++;
	}
	if (count > A->length / 2)
		*x = elem;
	else
		*x = -1;
}
void find_middle_number_page18_11_method2(SqList* A, SqList* B, ElemType* mid_elem)
{
	SqList C;
	int i, j, mid;

	init_list(&C);
	mid = (A->length + B->length) / 2;
	i = j = 0;
	while (i < A->length && j < B->length)
	{
		if (A->base[i] < B->base[j])
		{
			insert_list(&C, C.length + 1, A->base[i]);
			++i;
		}
		else
		{
			insert_list(&C, C.length + 1, B->base[j]);
			++j;
		}
		if (mid == C.length)
		{
			*mid_elem = C.base[C.length - 1];
			return;
		}
	}
	while (i < A->length)
	{
		insert_list(&C, C.length + 1, A->base[i]);
		++i;
		if (mid == C.length)
		{
			*mid_elem = C.base[C.length - 1];
			return;
		}
	}
	while (j < B->length)
	{
		insert_list(&C, C.length + 1, B->base[j]);
		++j;
		if (mid == C.length)
		{
			*mid_elem = C.base[C.length - 1];
			return;
		}
	}
}

void find_middle_number_page18_11(SqList* A, SqList* B, ElemType* mid_elem)
{
	// A->length == B->length
	int a1 = 0, a2 = A->length - 1, b1 = 0, b2 = B->length - 1;
	int amid, bmid;

	while (a1 < a2)
	{
		amid = (a1 + a2) / 2;
		bmid = (b1 + b2) / 2;
		if (A->base[amid] == B->base[bmid])
		{
			*mid_elem = A->base[amid];
			return;
		}
		if (A->base[amid] < B->base[bmid])
		{
			if ((a1 + a2) % 2 == 0)
			{
				a1 = amid;
				b2 = bmid;
			}
			else
			{
				a1 = amid + 1;
				b2 = bmid;
			}
		}
		else
		{
			if ((a1 + a2) % 2 == 0)
			{
				a2 = amid;
				b1 = bmid;
			}
			else
			{
				a2 = amid;
				b1 = bmid + 1;
			}
		}
	}
	*mid_elem = (A->base[a1] < B->base[b1]) ? A->base[a1] : B->base[b1];
}

void reverse_page18_10(SqList* A, int from, int to)
{
	if (from < 0 || from > to || to > A->length - 1)
	{
		printf("\nError: invalid parameters!!!!");
		exit(1);
	}
	int i, j;
	ElemType temp;
	for (i = from, j = to; i < j; ++i, --j)
	{
		temp = A->base[i];
		A->base[i] = A->base[j];
		A->base[j] = temp;
	}
}

void circular_move_page18_10(SqList* A, int moves)
{
	if (moves <= 0 || moves >= A->length)
	{
		printf("\nError: invalid parameters!!!");
		exit(1);
	}
	reverse_page18_10(A, 0, moves - 1);
	reverse_page18_10(A, moves, A->length - 1);
	reverse_page18_10(A, 0, A->length - 1);
}
void search_page18_9(SqList* A, ElemType x)
{
	int start, end, mid;
	ElemType temp;

	if (A->length == 0)
	{
		insert_list(A, 1, x);
		return;
	}
	start = 0, end = A->length - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (x < A->base[mid])
			end = mid - 1;
		else if (x > A->base[mid])
			start = mid + 1;
		else
			break;
	}
	if (x == A->base[mid] && mid != A->length - 1)
	{
		temp = A->base[mid];
		A->base[mid] = A->base[mid + 1];
		A->base[mid + 1] = temp;
		return;
	}
	if (start > end)
	{
		insert_list(A, start + 1, x);
	}
}

void reverse_page18_8(SqList* A, int start, int end)
{
	if (start < 0 || start > end || end >= A->length)
	{
		printf("\nError: invalid parameters!!!");
		exit(1);
	}
	int i, j;
	ElemType temp;
	for (i = start, j = end; i < j; ++i, --j)
	{
		temp = A->base[i];
		A->base[i] = A->base[j];
		A->base[j] = temp;
	}
}

void exchange_page18_8(SqList* A, int m, int n)
{
	if (m < 1 || n < 1 || (m + n != A->length))
	{
		printf("\nError: invalid parameters!!!");
		exit(1);
	}
	reverse_page18_8(A, 0, m + n - 1);
	reverse_page18_8(A, 0, n - 1);
	reverse_page18_8(A, n, m + n - 1);
}
void merge_page18_7(SqList* list_1, SqList* list_2, SqList* merged_list)
{
	int i, j;

	i = j = 0;
	while (i < list_1->length && j < list_2->length)
	{
		if (list_1->base[i] < list_2->base[j])
		{
			insert_list(merged_list, merged_list->length + 1, list_1->base[i]);
			++i;
		}
		else
		{
			insert_list(merged_list, merged_list->length + 1, list_2->base[j]);
			++j;
		}
	}
	while (i < list_1->length)
	{
		insert_list(merged_list, merged_list->length + 1, list_1->base[i]);
		++i;
	}
	while (j < list_2->length)
	{
		insert_list(merged_list, merged_list->length + 1, list_2->base[j]);
		++j;
	}
}

void init_list(SqList* list)
{
	list->base = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
	if (list->base == NULL)
	{
		printf("Error: malloc failure!!!!\n");
		exit(0);
	}
	list->total_size = INIT_SIZE;
	list->length = 0;
}

void insert_list(SqList* list, int position, ElemType elem)
{
	// 1 <= position <= length+1
	if (position < 1 || position > list->length + 1)
	{
		printf("Error: invalid parameters!!!!\n");
		exit(0);
	}
	ElemType* p = NULL;
	if (list->length >= list->total_size)
	{
		p = (ElemType*)realloc(list->base, (list->total_size + INCREMENT_SIZE) * sizeof(ElemType));
		if (p == NULL)
		{
			printf("\nError: realloc failure!!!");
			exit(0);
		}
		list->base = p;
		list->total_size += INCREMENT_SIZE;
	}
	int i;
	for (i = list->length - 1; i >= position - 1; --i)
	{
		list->base[i + 1] = list->base[i];
	}
	list->base[position - 1] = elem;
	list->length++;
}

void create_list(SqList* list)
{
	int count, i;
	ElemType elem;

	printf("\nHow many elements in the list:");
	scanf_s("%d", &count);
	printf("\nEnter %d integers:\n", count);
	for (i = 1; i <= count; i++)
	{
		scanf_s("%d", &elem);
		insert_list(list, list->length + 1, elem);
	}
}

void print_list(SqList* list)
{
	int i;

	printf("\n\n=====the list=====\n");
	for (i = 0; i < list->length; i++)
	{
		printf("%d, ", list->base[i]);
	}
	printf("\n\n");
}

// page 18, 3
void delete_all_x(SqList* list, ElemType x)
{
	int i, j;

	j = 0;
	for (i = 0; i < list->length; i++)
	{
		if (list->base[i] != x)
		{
			list->base[j++] = list->base[i];
		}
	}
	list->length = j;
}

// page 18, 4
void delete_x_between(SqList* list, ElemType lower_bound, ElemType upper_bound)
{
	if (lower_bound > upper_bound)
	{
		printf("\nError: invalid parameters!!!");
		exit(0);
	}
	int i, m, n;
	for (i = 0; i < list->length; i++)
	{
		if (list->base[i] >= lower_bound)
			break;
	}
	if (i < list->length)
	{
		m = i;
		while (i < list->length)
		{
			if (list->base[i] > upper_bound)
				break;
			++i;
		}
		if (i == list->length)
		{
			list->length = m;
			return;
		}
		n = i;
		while (n < list->length)
		{
			list->base[m++] = list->base[n++];
		}
		list->length = m;
	}
}

void delete_page18_5(SqList* list, ElemType lower_bound, ElemType upper_bound)
{
	if (lower_bound > upper_bound)
	{
		printf("\nError: invalid parameter!!!");
		exit(0);
	}
	int count = 0, i;
	for (i = 0; i < list->length; i++)
	{
		if (list->base[i] < lower_bound || list->base[i] > upper_bound)
		{
			list->base[i - count] = list->base[i];
		}
		else
		{
			count++;
		}
	}
	list->length -= count;
}

void delete_page18_6(SqList* list)
{
	int i, j;

	for (j = 0, i = 1; i < list->length; i++)
	{
		if (list->base[i] != list->base[j])
		{
			list->base[++j] = list->base[i];
		}
	}
	list->length = j + 1;
}