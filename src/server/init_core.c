/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** init_core
*/

#include "../../include/server/server.h"

/**
 * @brief Initialize the core of the server
 *
 * @param argc Arguments count
 * @param argv Arguments
 * @param core Core of the server
 */
void init_core(const int argc, const char **argv, core_t *core)
{
    get_arguments(&core->arguments, argc, argv);
    init_map(&core->map, &core->arguments);
    init_players(&core->players, &core->arguments);
    refill_map(core);
}
