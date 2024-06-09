/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** seg
*/

#include "server.h"

void send_seg_info(char *team_name, int fd)
{
    send_response("seg ", fd);
    send_response(team_name, fd);
    send_response("\n", fd);
}

void seg(players_t *players, char *team_name)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_seg_info(team_name, tmp->fd);
        }
    }
}
