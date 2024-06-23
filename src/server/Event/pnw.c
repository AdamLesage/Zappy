/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pnw
*/

#include "server.h"

void send_pnw_info(network_t *network, player_info_t *player_info, int fd)
{
    add_to_send_buffer(network, "pnw ", fd);
    add_int_to_send_buffer(network, player_info->id, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, player_info->pos_x, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, player_info->pos_y, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, player_info->orientation, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, player_info->level, fd);
    add_to_send_buffer(network, " ", fd);
    add_to_send_buffer(network, player_info->team_name, fd);
    add_to_send_buffer(network, "\n", fd);
}

/**
 * @brief Category: Event | Pnw event => Player connection
 *
 * @param core
 * @param player_info
 */
void pnw(core_t *core, player_info_t *player_info)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pnw_info(&core->network, player_info, tmp->fd);
        }
    }
}
