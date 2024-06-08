/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pnw
*/

#include "server.h"

void send_pnw_info(player_info_t *player_info, int fd)
{
    send_response("pnw ", fd);
    send_response_int(player_info->id, fd);
    send_response(" ", fd);
    send_response_int(player_info->pos_x, fd);
    send_response(" ", fd);
    send_response_int(player_info->pos_y, fd);
    send_response(" ", fd);
    send_response_int(player_info->orientation, fd);
    send_response(" ", fd);
    send_response_int(player_info->level, fd);
    send_response(" ", fd);
    send_response(player_info->team_name, fd);
    send_response("\n", fd);
}

void pnw(players_t *players, player_info_t *player_info)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pnw_info(player_info, tmp->fd);
        }
    }
}
