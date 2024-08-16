/*
** EPITECH PROJECT, 2023
** .h
** File description:
** .h
*/


#ifndef GENERATOR_H_
    #define GENERATOR_H_
    #include "../../include/dante.h"
    typedef struct map {
        int** map;
        int f;
        int c;
        int direccion;
        int dir_x;
        int dir_y;
        int ny;
        int nx;
        int x;
        int y;
        int i;
    }maze_t;
    void gen(maze_t* map);
    void gen_maze(maze_t* map);
    maze_t* init_map(int f, int c);
    int auxiliar_function(maze_t* map, int a, int b);
    void cambiar_valoresfin(maze_t* map);
    void free_memory(maze_t* map);
    void print_map(maze_t* map);
    int cambiar_valores(maze_t* map);
    void free_map(maze_t* map);
    void initialise_values(maze_t* map);
    void print_aux(maze_t* map, int i, int j);
#endif /*GENERATOR_H_*/
