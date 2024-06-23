/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_number_client_by_teams
*/

#include "../../../../include/server/server.h"

/**
 * @brief Get the number of client by teams
 *
 * @param argv The arguments
 * @param index The index of the arguments
 * @return int The number of client by teams
 */
int get_number_client_by_teams(const char **argv, int *index)
{
    int nb_client = 0;

    if (argv[*index + 1] == NULL) {
        print_usage("nb_client not found");
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        print_usage("nb_client must be a number");
    }
    nb_client = atoi(argv[*index]);
    if (nb_client <= 0) {
        print_usage("nb_client must be > 0");
    }
    return (nb_client);
}
