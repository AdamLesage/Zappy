/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** main
*/

#include "../../include/server/server.h"

void signal_handler(int sig)
{
    sig = sig;
}

void sigpipe_handler(int sig)
{
    sig = sig;
}

int main(const int argc, const char **argv)
{
    core_t core;

    signal(SIGINT, signal_handler);
    signal(SIGPIPE, sigpipe_handler);
    init_core(argc, argv, &core);
    init_server(&core);
    lunch_server(&core); 
    close_server(&core);
    return (0);
}
