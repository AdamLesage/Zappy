/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_number_client_by_teams
*/

#include "../../../../include/server/server.h"

int get_number_client_by_teams(const char **argv, int *index)
{
    int nb_client = 0;

    if (argv[*index + 1] == NULL) {
        exit(84);
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        exit(84);
    }
    nb_client = atoi(argv[*index]);
    if (nb_client <= 0) {
        exit(84);
    }
    return (nb_client);
}
