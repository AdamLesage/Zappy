/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_arguments
*/

#include "../../../../include/server/server.h"

static void init_arguments(arguments_t *arguments)
{
    arguments->frequency = 100;
    arguments->height = -1;
    arguments->width = -1;
    arguments->nb_client = -1;
    arguments->port = -1;
    arguments->nb_teams = -1;
    arguments->name_teams = NULL;
}

static bool get_flag2(arguments_t *arguments, const char **argv, int *index)
{
    if (strcmp(argv[*index], "-n") == 0) {
        get_teams_name(arguments, argv, index);
        return (true);
    }
    if (strcmp(argv[*index], "-c") == 0) {
        arguments->nb_client = get_number_client_by_teams(argv, index);
        return (true);
    }
    if (strcmp(argv[*index], "-f") == 0) {
        arguments->frequency = get_frequency(argv, index);
        return (true);
    }
    return (false);
}

static bool get_flag(arguments_t *arguments, const char **argv, int *index)
{
    if (strcmp(argv[*index], "-p") == 0) {
        arguments->port = get_port(argv, index);
        return (true);
    }
    if (strcmp(argv[*index], "-x") == 0) {
        arguments->width = get_width(argv, index);
        return (true);
    }
    if (strcmp(argv[*index], "-y") == 0) {
        arguments->height = get_height(argv, index);
        return (true);
    }
    return get_flag2(arguments, argv, index);
}

void print_usage(char *error)
{
    dprintf(2, "Error: %s\n", error);
    dprintf(2, "USAGE: ./zappy_server -p port -x width -y height"
        " -n name1 name2 ... -c clientsNb -f freq\n");
    exit(84);
}

/**
 * @brief Get the arguments of the server
 *
 * @param arguments
 * @param argc
 * @param argv
 */
void get_arguments(arguments_t *arguments, const int argc, const char **argv)
{
    bool is_valid = false;

    init_arguments(arguments);
    if (argc <= 1) {
        print_usage("not enough arguments");
    }
    for (int i = 1; argv[i] != NULL; i++) {
        is_valid = get_flag(arguments, argv, &i);
        if (is_valid == false)
            print_usage("unknow flag");
    }
    if (arguments->height == -1 || arguments->width == -1 ||
        arguments->port == -1) {
        print_usage("missing mandatory flag");
    }
    if (arguments->nb_teams == -1 || arguments->nb_client == -1) {
        print_usage("missing mandatory flag");
    }
}
