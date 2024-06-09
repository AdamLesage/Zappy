/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** edi
*/

#include "server.h"

static void send_edi_info(int egg_id, int fd)
{
    send_response("edi ", fd);
    send_response_int(egg_id, fd);
    send_response("\n", fd);
}

void edi(players_t *players, int egg_id)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_edi_info(egg_id, tmp->fd);
        }
    }
}
