#ifndef _QUEUE_
#define _QUEUE_

#define OVERFLOW 1
#define INFEASIBLE 2

#define MAX_QUEUE_SPACE 5

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
void print_queue(Queue* queue);

#endif // !_QUEUE_
