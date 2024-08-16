/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/solver.h"

int main(int argc, char** argv)
{
    if (argc >= 2 && argc < 4) {
        open_file(argv[argc - 1]);
    } else {
        return 84;
    }
}

void free_map(maze_t* map)
{
    for (int i = 0; i < map->f; i++) {
        free(map->map[i]);
    }
    free(map->map);
    free(map);
}

int open_file(char *filename)
{
    char buffer[MAX_BUFFER];
    int f = open(filename, O_RDONLY);
    if (f == -1) {
        return 84;
    } else {
        read_file(f, buffer);
        return 0;
    }
}

void read_file(int file, char *buffer)
{
    int len = 0;
    int offset = 0;
    while ((len = read(file, buffer + offset, MAX_BUFFER - offset)) > 0) {
        offset += len;
    }
    buffer[offset] = '\0';
    read_maze(buffer);
    close(file);
}
