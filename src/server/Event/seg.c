/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** seg
*/

#include "server.h"

void send_seg_info(network_t *network, char *team_name, int fd)
{
    add_to_send_buffer(network, "seg ", fd);
    add_to_send_buffer(network, team_name, fd);
    add_to_send_buffer(network, "\n", fd);
}

/**
 * @brief Category: Event | Seg event => End of the game
 *
 * @param core
 * @param team_name
 */
void seg(core_t *core, char *team_name)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_seg_info(&core->network, team_name, tmp->fd);
        }
    }
}
