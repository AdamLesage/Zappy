/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** enw
*/

#include "server.h"

void send_enw_info(network_t *network, int player_id, eggs_t *eggs, int fd)
{
    add_to_send_buffer(network, "enw ", fd);
    add_int_to_send_buffer(network, eggs->egg_id, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, player_id, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, eggs->pos_x, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, eggs->pos_y, fd);
    add_to_send_buffer(network, "\n", fd);
}

/**
 * @brief Category: Event | Enw event => An egg is laid
 *
 * @param core
 * @param player_id
 * @param eggs
 */
void enw(core_t *core, int player_id, eggs_t *eggs)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_enw_info(&core->network, player_id, eggs, tmp->fd);
        }
    }
}
