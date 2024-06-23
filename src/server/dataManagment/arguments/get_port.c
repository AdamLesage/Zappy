/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_port
*/

#include "../../../../include/server/server.h"

/**
 * @brief Get the port from the arguments
 *
 * @param argv The arguments
 * @param index The index of the arguments
 * @return int The port
 */
int get_port(const char **argv, int *index)
{
    int port = 0;

    if (argv[*index + 1] == NULL) {
        print_usage("port number not found");
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        print_usage("port must be a number");
    }
    port = atoi(argv[*index]);
    if (port <= 0) {
        print_usage("port must be > 0");
    }
    return (port);
}
