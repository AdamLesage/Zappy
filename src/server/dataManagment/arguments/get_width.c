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
        print_usage("width number not found");
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        print_usage("width must be a number");
    }
    width = atoi(argv[*index]);
    if (width <= 1) {
        print_usage("width must be > 1");
    }
    return (width);
}
