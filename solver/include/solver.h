/*
** EPITECH PROJECT, 2023
** .h
** File description:
** .h
*/


#ifndef SOLVER_H_
    #define SOLVER_H_
    #include "../../include/dante.h"
    typedef struct maze {
        int f;
        int c;
        int **map;
    } maze_t;
    maze_t* init_map(int f, int c);
    int open_file(char *filename);
    void print_map(maze_t* maze);
    void read_file(int file, char *buffer);
    void read_maze(char *buffer);
    int resolver(maze_t* maze, int y, int x);
    int function_recursive(maze_t* maze, int y, int x);
    int check_right(char a);
    void pass_to_map(char* buffer, maze_t* maze);
    void printer(maze_t* maze, int i, int j);
    void free_map(maze_t* map);
    int function_aux(char a, int n, int j, maze_t* maze);
#endif /*SOLVER_H_*/
