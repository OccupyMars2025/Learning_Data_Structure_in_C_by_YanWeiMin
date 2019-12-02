#ifndef _QUEUE_
#define _QUEUE_

#define OVERFLOW 1
#define INFEASIBLE 2

#define K 4
#define MAX_QUEUE_SPACE K

typedef int QElemType;
typedef struct
{
	QElemType* base;
	int front, rear, tag;
} Queue;

void init_queue(Queue* queue);
void destroy_queue(Queue* queue);
int is_empty(Queue* queue);
int is_full(Queue* queue);
void en_queue(Queue* queue, QElemType* elem);
void de_queue(Queue* queue, QElemType* elem);
void sum_queue(Queue* queue, int* result);
void print_fibonacci(int upper_bound);

#endif // !_QUEUE_
