/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** main
*/

#include "../../include/server/server.h"

/**
 * @brief Signal handler for SIGINT
 *
 * @param sig
 */
void signal_handler(int sig)
{
    sig = sig;
}

/**
 * @brief Signal handler for SIGPIPE
 *
 * @param sig
 */
void sigpipe_handler(int sig)
{
    sig = sig;
}

/**
 * @brief Print the arguments of the server, when the server is launched
 *
 * @param arguments
 */
static void print_arguments_server(arguments_t *arguments)
{
    printf("======================Zappy======================\n");
    printf("==============General info==============\n");
    printf("Frequency:\t%d\n", arguments->frequency);
    printf("Port:\t\t%d\n", arguments->port);
    printf("==============Map info==================\n");
    printf("Height:\t\t%d\n", arguments->height);
    printf("Width:\t\t%d\n", arguments->width);
    printf("==============Team info=================\n");
    printf("Nb_teams\t%d\n", arguments->nb_teams);
    printf("Nb_client:\t%d\n", arguments->nb_client);
    printf("Teams:\n");
    if (arguments->name_teams != NULL) {
        for (int i = 0; arguments->name_teams[i] != NULL; i++) {
            printf("\tTeam [%d]: %s\n", i, arguments->name_teams[i]);
        }
    }
    printf("=================================================\n");
}

/**
 * @brief Main function of the server
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(const int argc, const char **argv)
{
    core_t core;

    signal(SIGINT, signal_handler);
    signal(SIGPIPE, sigpipe_handler);
    init_core(argc, argv, &core);
    init_server(&core);
    print_arguments_server(&core.arguments);
    lunch_server(&core);
    close_server(&core);
    return (0);
}
