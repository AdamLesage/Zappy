/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** smg
*/

#include "server.h"

void send_smg_info(char *message, int fd)
{
    send_response("smg ", fd);
    send_response(message, fd);
    send_response("\n", fd);
}

void smg(players_t *players, char *message)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_smg_info(message, tmp->fd);
        }
    }
}
