/*
** EPITECH PROJECT, 2023
** generate
** File description:
** generate
*/

#include "../include/generator.h"

maze_t* init_map(int f, int c)
{
    maze_t* new_map = malloc(sizeof(maze_t));
    new_map->c = c;
    new_map->f = f;
    new_map->map = malloc(sizeof(int*) * new_map->f);
    for (int i = 0; i < new_map->f; i++) {
        new_map->map[i] = malloc(sizeof(int) * new_map->c);
    }
    return new_map;
}

void elegir_direccion(maze_t* map)
{
    map->dir_x = 0;
    map->dir_y = 0;
    if (map->direccion == 0) {
        map->dir_x = 1;
    }
    if (map->direccion == 1) {
        map->dir_y = 1;
    }
    if (map->direccion == 2) {
        map->dir_x = -1;
    }
    if (map->direccion == 3) {
        map->dir_y = -1;
    }
}

int auxiliar_function(maze_t* map, int a, int b)
{
    int found = 0;
    if (map->map[b][a] == 1) {
        map->direccion = rand() % 4;
        map->map[map->ny][map->nx] = 0;
        map->map[b][a] = 0;
        map->x = map->nx + map->dir_x;
        map->y = map->ny + map->dir_y;
        map->i = 0;
        found = 1;
    }
    return found;
}

void gen_maze(maze_t* map)
{
    map->direccion = rand() % 4;
    map->i = 0;
    while (map->i < 4) {
        elegir_direccion(map);
        map->nx = map->x + map->dir_x;
        map->ny = map->y + map->dir_y;
        cambiar_valores(map);
    }
}

void gen(maze_t* map)
{
    map->x = 1;
    map->y = 1;
    while (map->y < map->f) {
        while (map->x < map->c) {
            gen_maze(map);
            map->x = map->x + 2;
        }
        map->y = map->y + 2;
        map->x = 1;
    }
    cambiar_valoresfin(map);
    print_map(map);
    free_memory(map);
}
