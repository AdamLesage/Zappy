/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** edi
*/

#include "server.h"

static void send_edi_info(network_t *network, int egg_id, int fd)
{
    add_to_send_buffer(network, "edi ", fd);
    add_int_to_send_buffer(network, egg_id, fd);
    add_to_send_buffer(network, "\n", fd);
}

void edi(core_t *core, int egg_id)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_edi_info(&core->network, egg_id, tmp->fd);
        }
    }
}
