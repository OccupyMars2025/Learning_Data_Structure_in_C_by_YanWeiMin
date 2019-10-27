#ifndef _SEQUENTIAL_QUEUE_
#define _SEQUENTIAL_QUEUE_

#define MAX_QUEUE_SPACE 5
#define OVERFLOW 1
#define INFEASIBLE 2

typedef int QDataType;
typedef struct
{
	QDataType* base;
	int front;
	int rear;
} SqQueue;

void init_queue(SqQueue* queue);
int is_empty(SqQueue* queue);
int is_full(SqQueue* queue);
int queue_length(SqQueue* queue);
void destroy_queue(SqQueue* queue);
void en_queue(SqQueue* queue, QDataType data);
void de_queue(SqQueue* queue, QDataType* data);
void print_queue(SqQueue* queue);

#endif // !_SEQUENTIAL_QUEUE_
