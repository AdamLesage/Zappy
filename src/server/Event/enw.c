/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** enw
*/

#include "server.h"

void send_enw_info(int player_id, eggs_t *eggs, int fd)
{
    send_response("enw ", fd);
    send_response_int(eggs->egg_id, fd);
    send_response(" ", fd);
    send_response_int(player_id, fd);
    send_response(" ", fd);
    send_response_int(eggs->pos_x, fd);
    send_response(" ", fd);
    send_response_int(eggs->pos_y, fd);
    send_response("\n", fd);
}

void enw(players_t *players, int player_id, eggs_t *eggs)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_enw_info(player_id, eggs, tmp->fd);
        }
    }
}
