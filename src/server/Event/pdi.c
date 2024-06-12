/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pdi
*/

#include "server.h"

static void send_pdi_info(int id, int fd)
{
    send_response("pdi ", fd);
    send_response_int(id, fd);
    send_response("\n", fd);
}

void pdi(players_t *players, int id)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pdi_info(id, tmp->fd);
        }
    }
}
