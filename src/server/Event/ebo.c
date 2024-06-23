/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ebo
*/

#include "server.h"

static void send_ebo_info(network_t *network, int egg_id, int fd)
{
    add_to_send_buffer(network, "ebo ", fd);
    add_int_to_send_buffer(network, egg_id, fd);
    add_to_send_buffer(network, "\n", fd);
}

/**
 * @brief Category: Event | Ebo event => Player connection for an egg
 *
 * @param core
 * @param egg_id
 */
void ebo(core_t *core, int egg_id)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_ebo_info(&core->network, egg_id, tmp->fd);
        }
    }
}
