/*
** EPITECH PROJECT, 2023
** change
** File description:
** change
*/

#include "../include/generator.h"

void cambiar_valoresfin(maze_t* map)
{
    map->map[0][0] = 0;
    map->map[0][1] = 0;
    map->map[map->f - 1][map->c - 2] = 0;
    map->map[map->f - 1][map->c - 1] = 0;
}

int cambiar_valores(maze_t* map)
{
    int found = 0;
    int a = map->nx + map->dir_x;
    int b = map->ny + map->dir_y;
    if (a > 0 && a < map->c && b > 0 && b < map->f) {
        if (map->map[map->ny][map->nx] == 1) {
            found = auxiliar_function(map, a, b);
        }
    }
    if (found == 0) {
        map->i = map->i + 1;
        map->direccion = (map->direccion + 1) % 4;
    }
}

void print_aux(maze_t* map, int i, int j)
{
    if (map->map[i][j] == 1) {
        printf("X");
    } else {
        printf("*");
    }
}

void print_map(maze_t* map)
{
    for (int i = 0; i < map->f; i++) {
        for (int j = 0; j < map->c; j++) {
            print_aux(map, i, j);
        }
        printf("\n");
    }
    printf("\0");
}

void free_memory(maze_t* map)
{
    for (int i = 0; i < map->f; i++) {
        free(map->map[i]);
    }
    free(map->map);
    free(map);
}
