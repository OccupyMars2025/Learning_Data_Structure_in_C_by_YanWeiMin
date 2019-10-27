#ifndef _TWINS_STACK_
#define _TWINS_STACK_

#define OVERFLOW 1
#define INFEASIBLE 2

#define STACK_SPACE 100

typedef int SDataType;
typedef struct 
{
	SDataType* base0;
	SDataType* base1;
	SDataType* top0;
	SDataType* top1;
} Twins_Stack;

void init_stack(Twins_Stack* ts);
void destroy_stack(Twins_Stack* ts);
void push(Twins_Stack* ts, int which, SDataType data);
void pop(Twins_Stack* ts, int which, SDataType* data);
void print_stack(Twins_Stack* ts, int which);
int is_empty(Twins_Stack* ts, int which);

#endif // !_TWINS_STACK_
