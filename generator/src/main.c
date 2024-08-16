/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/generator.h"

int main(int argc, char** argv)
{
    if (argc > 2) {
        int a = my_getnbr(argv[1]);
        int b = my_getnbr(argv[2]);
        if (a == -1 || b == -1) {
            return ERROR_EXIT;
        } else {
            maze_t* map = init_map(a, b);
            initialise_values(map);
            gen(map);
            return EXIT_SUCCESS;
        }
    } else {
        return ERROR_EXIT;
    }
}

void initialise_values(maze_t* map)
{
    for (int i = 0; i < map->f; i++) {
        for (int j = 0; j < map->c; j++) {
            map->map[i][j] = 1;
        }
    }
}
