/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pbc
*/

#include "server.h"

static void send_pbc_info(network_t *network, int id, char *message, int fd)
{
    add_to_send_buffer(network, "pbc ", fd);
    add_int_to_send_buffer(network, id, fd);
    add_to_send_buffer(network, " ", fd);
    add_to_send_buffer(network, message, fd);
    add_to_send_buffer(network, "\n", fd);
}

/**
 * @brief Category: Event | Pbc event => Broadcast message
 *
 * @param core
 * @param id
 * @param message
 */
void pbc(core_t *core, int id, char *message)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pbc_info(&core->network, id, message, tmp->fd);
        }
    }
}
