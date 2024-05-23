/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_height
*/

#include "../../../../include/server/server.h"

int get_height(const char **argv, int *index)
{
    int height = 0;

    if (argv[*index + 1] == NULL) {
        exit(84);
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        exit(84);
    }
    height = atoi(argv[*index]);
    if (height <= 1) {
        exit(84);
    }
    return (height);
}
