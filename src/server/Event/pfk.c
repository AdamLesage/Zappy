/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pfk
*/

#include "server.h"

static void send_pfk_info(int id, int fd)
{
    send_response("pfk ", fd);
    send_response_int(id, fd);
    send_response("\n", fd);
}

void pfk(players_t *players, int id)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pfk_info(id, tmp->fd);
        }
    }
}
