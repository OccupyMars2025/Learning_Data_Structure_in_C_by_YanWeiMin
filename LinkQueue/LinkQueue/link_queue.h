#ifndef _LINK_QUEUE_
#define _LINK_QUEUE_

typedef int QDataType;
typedef struct QNode
{
	QDataType data;
	struct QNode* next;
} QNode;
typedef struct
{
	QNode* front;
	QNode* rear;
} LinkQueue;

void init_queue(LinkQueue* queue);
void destroy_queue(LinkQueue* queue);
void en_queue(LinkQueue* queue, QDataType data);
int is_empty(LinkQueue* queue);
void de_queue(LinkQueue* queue, QDataType* data);
void print_queue(LinkQueue* queue);

#endif // !_LINK_QUEUE_
