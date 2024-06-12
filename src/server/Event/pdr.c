/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pdr
*/

#include "server.h"

static void send_pdr_info(int id, enum Object object, int fd)
{
    send_response("pdr ", fd);
    send_response_int(id, fd);
    send_response(" ", fd);
    send_response_int(object, fd);
    send_response("\n", fd);
}

void pdr(players_t *players, int id, enum Object object)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pdr_info(id, object, tmp->fd);
        }
    }
}
