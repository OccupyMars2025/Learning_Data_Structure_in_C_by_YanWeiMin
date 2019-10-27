#include "maze.h"
#include<stdio.h>
#include<stdlib.h>

void init_stack(Stack* s)
{
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (s->base == NULL)
	{
		printf("\nmalloc failure!!!");
		exit(1);
	}
	s->top = s->base;
	s->stack_size = STACK_INIT_SIZE;
}

Status is_empty(Stack* s)
{
	if (s->top == s->base)
		return TRUE;
	else
		return FALSE;
}

void push(Stack* s, SElemType* e)
{
	SElemType* p;
	if (s->top - s->base >= s->stack_size)
	{
		p = (SElemType*)realloc(s->base, (s->stack_size + STACK_INCREMENT) * sizeof(SElemType));
		if (p == NULL)
		{
			free(s->base);
			printf("\nrealloc failure!!!");
			exit(1);
		}
		s->base = p;
		s->top = s->base + s->stack_size;
		s->stack_size += STACK_INCREMENT;
	}
	*(s->top) = *e;
	++(s->top);
}

void pop(Stack* s, SElemType* e)
{
	if (s->top != s->base)
	{
		--(s->top);
		*e = *(s->top);
	}
}

void get_top(Stack* s, SElemType* e)
{
	if (s->top != s->base)
	{
		*e = *(s->top - 1);
	}
}

void init_maze(Maze* maze, int map[ROW][COL])
{
	int i, j;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			maze->map[i][j] = map[i][j];
		}
	}
}

void find_path(Maze* maze, Position* entrance, Position* the_exit)
{
	void init_stack(Stack * s);
	Status is_empty(Stack * s);
	void push(Stack * s, SElemType * e);
	void pop(Stack * s, SElemType * e);
	void get_top(Stack * s, SElemType * e);

	Status is_passable(Maze * maze, Position * position);
	Position next_step(Position * position, int direction);

	Stack stack;
	SElemType elem;
	Position current_position;

	if (is_passable(maze, entrance) == FALSE || is_passable(maze, the_exit) == FALSE)
	{
		printf("\ninvalid entrance or exit !!!!");
		return;
	}
	init_stack(&stack);
	current_position = *entrance;
	do {
		if (is_passable(maze, &current_position) == TRUE) 
		{
			elem.position = current_position;
			elem.direction = 1;
			push(&stack, &elem);
			maze->map[current_position.y][current_position.x] = JUST_WALKED;
			if (current_position.x == the_exit->x && current_position.y == the_exit->y)
				return;
			current_position = next_step(&current_position, elem.direction);
		} 
		else
		{
			while (is_empty(&stack) == FALSE)
			{
				pop(&stack, &elem);
				if (elem.direction == 4)
				{
					maze->map[elem.position.y][elem.position.x] = DEPRECATED;
				}
				else
				{
					current_position = next_step(&(elem.position), ++elem.direction);
					push(&stack, &elem);
					break;
				}
			}
		}
	} while (is_empty(&stack) == FALSE);
}

void print_maze(Maze* maze)
{
	int i, j;

	printf("\n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d ", maze->map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

Status is_passable(Maze* maze, Position* position)
{
	int x, y;

	x = position->x;
	y = position->y;
	if (x < 0 || x >= COL || y < 0 || y >= ROW)
		return FALSE;
	if (maze->map[y][x] == PASSABLE)
		return TRUE;
	else
		return FALSE;
}

Position next_step(Position* position, int direction)
{
	//direction: 1=north, 2=east, 3=south, 4=west
	Position temp;

	switch (direction)
	{
		case 1:
			temp.y = position->y - 1;
			temp.x = position->x;
			break;
		case 2:
			temp.y = position->y;
			temp.x = position->x + 1;
			break;
		case 3:
			temp.y = position->y + 1;
			temp.x = position->x;
			break;
		case 4:
			temp.y = position->y;
			temp.x = position->x - 1;
			break;
		default:
			temp.y = position->y - 1;
			temp.x = position->x;
			break;
	}

	return temp;
}