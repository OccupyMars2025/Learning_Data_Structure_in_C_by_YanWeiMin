#include "maze.h"

int main()
{
	int map[ROW][COL] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
		{ 0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
		{ 0, 1, 1, 1, 1, 0, 0, 1, 1, 0},
		{ 0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
		{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
		{ 0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
		{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
		{ 0, 0, 1, 1, 1, 1, 1, 0, 1, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	Position entrance = { 1, 1 }, the_exit = { 8, 8 };
	
	Maze maze;

	init_maze(&maze, map);
	print_maze(&maze);
	find_path(&maze, &entrance, &the_exit);
	print_maze(&maze);

	return 0;
}