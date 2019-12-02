#ifndef _MY_FUNCTION_
#define _MY_FUNCTION_

#define INIT_SIZE 3
#define INCREMENT_SIZE 2

typedef int ElemType;
typedef struct
{
	ElemType* base;
	int total_size, length;
} SqList;

void init_list(SqList* list);
void insert_list(SqList* list, int position, ElemType elem);
void create_list(SqList* list);
void print_list(SqList* list);
void delete_all_x(SqList* list, ElemType x);
void delete_x_between(SqList* list, ElemType lower_bound, ElemType upper_bound);
void delete_page18_5(SqList* list, ElemType lower_bound, ElemType upper_bound);
void delete_page18_6(SqList* list);
void merge_page18_7(SqList* list_1, SqList* list_2, SqList* merged_list);
void reverse_page18_8(SqList* A, int start, int end);
void exchange_page18_8(SqList* A, int m, int n);
void search_page18_9(SqList* A, ElemType x);
void reverse_page18_10(SqList* A, int from, int to);
void circular_move_page18_10(SqList* A, int moves);
void find_middle_number_page18_11(SqList* A, SqList* B, ElemType* mid_elem);
void find_middle_number_page18_11_method2(SqList* A, SqList* B, ElemType* mid_elem);
void find_most_occurence(SqList* A, ElemType* x);

#endif // !_MY_FUNCTION_
