/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pie
*/

#include "server.h"

static void send_pie_info(int x, int y, bool state, int fd)
{
    send_response("pie ", fd);
    send_response_int(x, fd);
    send_response(" ", fd);
    send_response_int(y, fd);
    send_response(" ", fd);
    send_response_int(state, fd);
    send_response("\n", fd);
}

void pie(players_t *players, int x, int y, bool state)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pie_info(x, y, state, tmp->fd);
        }
    }
}
