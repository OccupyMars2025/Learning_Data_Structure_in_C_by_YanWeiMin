#ifndef _MAZE_H_
#define _MAZE_H_

#define TRUE 1
#define FALSE 0
#define OVERFLOW 2
#define STACK_INIT_SIZE 2
#define STACK_INCREMENT 3
#define ROW 10
#define COL 10

#define WALL 0
#define PASSABLE 1
#define JUST_WALKED 2
#define DEPRECATED 3

typedef int Status;
typedef struct
{
	int x;
	int y;
} Position;
typedef struct
{
	Position position;
	int direction;
} SElemType;
typedef struct 
{
	SElemType* base;
	SElemType* top;
	int stack_size;
} Stack;
typedef struct 
{
	int map[ROW][COL];
} Maze;

void init_stack(Stack* s);
Status is_empty(Stack* s);
void push(Stack* s, SElemType* e);
void pop(Stack* s, SElemType* e);
void get_top(Stack* s, SElemType* e);
void init_maze(Maze* maze, int map[ROW][COL]);
void find_path(Maze* maze, Position* entrance, Position* the_exit);
void print_maze(Maze* maze);
Status is_passable(Maze* maze, Position* position);
Position next_step(Position* position, int direction);

#endif // !_MAZE_H_

