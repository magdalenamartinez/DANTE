/*
** EPITECH PROJECT, 2023
** read.c
** File description:
** read
*/

#include "../include/solver.h"

int check_right(char a)
{
    if (a == 'X') {
        return 0;
    }
    if (a == '*') {
        return 0;
    }
    if (a == '\n') {
        return 0;
    }
    return -1;
}

void read_maze(char *buffer)
{
    int i = 0, f = 0;
    int col = 0, check = 0;
    while (buffer[i] != '\0' && check == 0) {
        check = check_right(buffer[i]);
        if (buffer[i] == '\n') {
            f++;
        }
        i++;
    }
    if (check == -1) {
        printf("No solution found\n");
        return;
    }
    while (buffer[col] != '\n') {
        col++;
    }
    maze_t* maze = init_map(f, col);
    pass_to_map(buffer, maze);
    resolver(maze, 0, 0);
    print_map(maze); free_map(maze);
}

int function_recursive(maze_t* maze, int y, int x)
{
    if (resolver(maze, y + 1, x) == 1) {
        return 1;
    }
    if (resolver(maze, y - 1, x) == 1) {
        return 1;
    }
    if (resolver(maze, y, x - 1) == 1) {
        return 1;
    }
    if (resolver(maze, y, x + 1) == 1) {
        return 1;
    }
    return 0;
}

int resolver(maze_t* maze, int y, int x)
{
    if (y < 0 || x < 0 || y >= maze->f) {
        return 0;
    }
    if (x >= maze->c || maze->map[y][x] != 0) {
        return 0;
    }
    maze->map[y][x] = 2;
    if ((y == maze->f - 1 && x == maze->c - 1) ||
    function_recursive(maze, y, x) == 1) {
        maze->map[y][x] = 3;
        return 1;
    } else {
        return 0;
    }
}

int function_aux(char a, int n, int j, maze_t* maze)
{
    if (a == 'X') {
        maze->map[n][j] = 1; j++;
    }
    if (a == '*') {
        maze->map[n][j] = 0; j++;
    }
    return j;
}
