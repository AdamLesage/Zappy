/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pex
*/

#include "server.h"

static void send_pex_info(player_info_t *player_info, int fd)
{
    send_response("pex ", fd);
    send_response_int(player_info->id, fd);
    send_response("\n", fd);
}

void pex(players_t *players, player_info_t *player_info)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pex_info(player_info, tmp->fd);
        }
    }
}
