/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_port
*/

#include "../../../../include/server/server.h"

int get_port(const char **argv, int *index)
{
    int port = 0;

    if (argv[*index + 1] == NULL) {
        exit(84);
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        exit(84);
    }
    port = atoi(argv[*index]);
    if (port <= 0) {
        exit(84);
    }
    return (port);
}
