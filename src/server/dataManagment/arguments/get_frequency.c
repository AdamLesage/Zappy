/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_frequency
*/

#include "../../../../include/server/server.h"

int get_frequency(const char **argv, int *index)
{
    int frequency = 0;

    if (argv[*index + 1] == NULL) {
        exit(84);
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        exit(84);
    }
    frequency = atoi(argv[*index]);
    if (frequency <= 1) {
        exit(84);
    }
    return (frequency);
}
