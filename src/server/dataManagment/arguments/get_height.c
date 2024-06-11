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
        print_usage("height missing number");
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        print_usage("height must be a number");
    }
    height = atoi(argv[*index]);
    if (height <= 1) {
        print_usage("height must be > 1");
    }
    return (height);
}
