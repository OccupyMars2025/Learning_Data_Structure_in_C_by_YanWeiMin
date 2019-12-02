#ifndef _QUEUE_
#define _QUEUE_

#define OVERFLOW 1
#define INFEASIBLE 2

typedef int QElemType;
typedef struct Node
{
	QElemType data;
	struct Node* next;
} QNode;
typedef struct
{
	QNode* rear;
} Queue;

void init_queue(Queue* q);
int is_empty(Queue* q);
void en_queue(Queue* q, QElemType* data);
void de_queue(Queue* q, QElemType* data);
void destroy_queue(Queue* q);
void print_queue(Queue* q);

#endif // !_QUEUE_
