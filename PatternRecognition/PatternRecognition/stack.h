#ifndef _STACK_
#define _STACK_

#define OVERFLOW 1
#define INFEASIBLE 2

#define STACK_INIT_SPACE 3
#define STACK_INCREMENT 2

typedef char SDataType;
typedef struct
{
	SDataType* base;
	SDataType* top;
	int stack_space;
} Stack;

void init_stack(Stack* s);
void destroy_stack(Stack* s);
int is_empty(Stack* s);
void push(Stack* s, SDataType* data);
void pop(Stack* s, SDataType* data);
void get_top(Stack* s, SDataType* data);

#endif // !_STACK_
