/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** init_core
*/

#include "../../include/server/server.h"

void init_core(const int argc, const char **argv, core_t *core)
{
    get_arguments(&core->arguments, argc, argv);
    init_map(&core->map, &core->arguments);
    init_players(&core->players, &core->arguments);
}
