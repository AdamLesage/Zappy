/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_width
*/

#include "../../../../include/server/server.h"

int get_width(const char **argv, int *index)
{
    int width = 0;

    if (argv[*index + 1] == NULL) {
        exit(84);
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        exit(84);
    }
    width = atoi(argv[*index]);
    if (width <= 1) {
        exit(84);
    }
    return (width);
}
