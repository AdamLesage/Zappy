/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_player_team
*/

#include "server.h"

char *get_player_team(players_t *players, int fd)
{
    player_info_t *info = find_player(players, fd);

    if (info == NULL) {
        return NULL;
    }
    return strdup(info->team_name);
}
