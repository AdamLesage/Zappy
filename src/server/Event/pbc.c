/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pbc
*/

#include "server.h"

static void send_pbc_info(int id, char *message, int fd)
{
    send_response("pbc ", fd);
    send_response_int(id, fd);
    send_response(" ", fd);
    send_response(message, fd);
    send_response("\n", fd);
}

void pbc(players_t *players, int id, char *message)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pbc_info(id, message, tmp->fd);
        }
    }
}
