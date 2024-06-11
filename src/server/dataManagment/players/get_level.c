/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_level
*/

#include "server.h"

int get_level(players_t *players, int fd)
{
    player_info_t *info = find_player(players, fd);

    if (info == NULL) {
        return -1;
    }
    return info->level;
}
