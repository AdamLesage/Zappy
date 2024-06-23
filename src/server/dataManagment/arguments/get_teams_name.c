/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_teams_name
*/

#include "../../../../include/server/server.h"

/**
 * @brief Get the teams name from the arguments
 *
 * @param arguments The arguments
 * @param argv The arguments
 * @param index The index of the arguments
 */
void get_teams_name(arguments_t *arguments, const char **argv, int *index)
{
    arguments->nb_teams = 0;
    (*index)++;
    for (int i = (*index); argv[i] != NULL && argv[i][0] != '-'; i++) {
        arguments->nb_teams++;
    }
    if (arguments->nb_teams == 0) {
        print_usage("number of teams must be > 0");
    }
    arguments->name_teams = malloc(sizeof(char *) * (arguments->nb_teams + 1));
    for (int i = 0; argv[(*index)] != NULL && argv[(*index)][0] != '-';
        (*index)++) {
        arguments->name_teams[i] = strdup(argv[*index]);
        i++;
        arguments->name_teams[i] = NULL;
    }
    (*index)--;
}
