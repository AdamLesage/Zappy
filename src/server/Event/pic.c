/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pic
*/

#include "server.h"

static void send_pic_info(incantation_info_t *info, int fd)
{
    send_response("pic ", fd);
    send_response_int(info->pos_x, fd);
    send_response(" ", fd);
    send_response_int(info->pos_y, fd);
    send_response(" ", fd);
    send_response_int(info->incantation_level, fd);
    for (int i = 0; info->ids[i] != -1; i ++) {
        send_response(" ", fd);
        send_response_int(info->ids[i], fd);
    }
    send_response("\n", fd);
}

void pic(players_t *players, incantation_info_t *info)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pic_info(info, tmp->fd);
        }
    }
}
