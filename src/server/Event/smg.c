/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** smg
*/

#include "server.h"

void send_smg_info(network_t *network, char *message, int fd)
{
    add_to_send_buffer(network, "smg ", fd);
    add_to_send_buffer(network, message, fd);
    add_to_send_buffer(network, "\n", fd);
}

void smg(core_t *core, char *message)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_smg_info(&core->network, message, tmp->fd);
        }
    }
}
