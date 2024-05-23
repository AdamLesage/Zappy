/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** main
*/

#include "../../include/server/server.h"

int main(const int argc, const char **argv)
{
    core_t core;

    init_core(argc, argv, &core);
    init_server(&core);
    lunch_server(&core);
    close_server(&core);
    return (0);
}
