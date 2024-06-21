/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pex
*/

#include "server.h"

static void send_pex_info(network_t *network,
    player_info_t *player_info, int fd)
{
    add_to_send_buffer(network, "pex ", fd);
    add_int_to_send_buffer(network, player_info->id, fd);
    add_to_send_buffer(network, "\n", fd);
}

void pex(core_t *core, player_info_t *player_info)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pex_info(&core->network, player_info, tmp->fd);
        }
    }
}
