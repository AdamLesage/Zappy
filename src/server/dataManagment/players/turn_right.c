/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** turn_right
*/

#include "server.h"

void turn_right(players_t *players, int fd)
{
    player_info_t *info = find_player(players, fd);

    if (info == NULL) {
        return;
    }
    switch (info->orientation) {
        case N:
            info->orientation = E;
            break;
        case E:
            info->orientation = S;
            break;
        case S:
            info->orientation = W;
            break;
        case W:
            info->orientation = N;
            break;
    }
}
