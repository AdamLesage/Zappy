/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pdr
*/

#include "server.h"

static void send_pdr_info(network_t *network, int id,
    enum Object object, int fd)
{
    add_to_send_buffer(network, "pdr ", fd);
    add_int_to_send_buffer(network, id, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, object, fd);
    add_to_send_buffer(network, "\n", fd);
}

void pdr(core_t *core, int id, enum Object object)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pdr_info(&core->network, id, object, tmp->fd);
        }
    }
}
