/*
** EPITECH PROJECT, 2023
** map.c
** File description:
** map
*/

#include "../include/solver.h"

void pass_to_map(char* buffer, maze_t* maze)
{
    int i = 0;
    int n = 0;
    int j = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            n++; j = 0;
        } else {
            j = function_aux(buffer[i], n, j, maze);
        }
        i++;
    }
}

void printer(maze_t* maze, int i, int j)
{
    if (maze->map[i][j] == 1) {
        printf("X");
    }
    if (maze->map[i][j] == 3) {
        printf("o");
    }
    if (maze->map[i][j] != 1 && maze->map[i][j] != 3) {
        printf("*");
    }
}

void print_map(maze_t* maze)
{
    for (int i = 0; i < maze->f; i++){
        for (int j = 0; j < maze->c; j++) {
            printer(maze, i, j);
        }
        printf("\n");
    }
}

maze_t* init_map(int f, int c)
{
    maze_t* newmap = malloc(sizeof(maze_t));
    newmap->f = f;
    newmap->c = c;
    newmap->map = malloc(sizeof(int*) * f);
    for (int i = 0; i < f; i++) {
        newmap->map[i] = malloc(sizeof(int) * c);
    }
    return newmap;
}
