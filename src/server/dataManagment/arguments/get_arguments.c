/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_arguments
*/

#include "../../../../include/server/server.h"

static void init_arguments(arguments_t *arguments)
{
    arguments->frequence = 100;
    arguments->height = -1;
    arguments->width = -1;
    arguments->nb_client = -1;
    arguments->port = -1;
    arguments->name_teams = NULL;
}

void get_arguments(arguments_t *arguments, const int argc, const char **argv)
{
    bool is_valid = false;

    init_arguments(arguments);
    if (argc <= 1)
        exit(84);
    for (int i = 1; argv[i] != NULL; i++) {
        is_valid = false;
        if (strcmp(argv[i], "-p") == 0) {
            arguments->port = get_port(argv, &i);
            is_valid = true;
        }
        if (is_valid == false)
            exit(84);
    }
}
