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
        print_usage("no frequency");
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        print_usage("frequency must be a number");
    }
    frequency = atoi(argv[*index]);
    if (frequency <= 1) {
        print_usage("frequency must be > 1");
    }
    return (frequency);
}
