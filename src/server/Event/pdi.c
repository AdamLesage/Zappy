/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pdi
*/

#include "server.h"

static void send_pdi_info(network_t *network, int id, int fd)
{
    add_to_send_buffer(network, "pdi ", fd);
    add_int_to_send_buffer(network, id, fd);
    add_to_send_buffer(network, "\n", fd);
}

/**
 * @brief Category: Event | Pdi event => Death of a player
 *
 * @param core
 * @param id
 */
void pdi(core_t *core, int id)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pdi_info(&core->network, id, tmp->fd);
        }
    }
}
