#ifndef _STACK_
#define _STACK_

#define OVERFLOW 1
#define INFEASIBLE 2

#define STACK_INIT_SPACE 2
#define STACK_INCREMENT 2

typedef char SElemType;
typedef struct
{
	SElemType* base;
	SElemType* top;
	int stack_space;
} Stack;

void init_stack(Stack* s);
void destroy_stack(Stack* s);
int is_empty(Stack* s);
void push(Stack* s, SElemType* e);
void pop(Stack* s, SElemType* e);
void get_top(Stack* s, SElemType* e);

#endif // !_STACK_
