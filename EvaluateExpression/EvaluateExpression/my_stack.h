#ifndef _MY_STACK_
#define _MY_STACK_

#define STACK_INIT_SIZE 2
#define STACK_INCREMENT 2

typedef int SElemType;
typedef struct
{
	SElemType* base;
	SElemType* top;
	int stack_size;
} Stack;

void init_stack(Stack* stack);
int is_empty(Stack* stack);
void push(Stack* stack, SElemType elem);
void pop(Stack* stack, SElemType* elem);
void get_top(Stack* stack, SElemType* elem);

#endif