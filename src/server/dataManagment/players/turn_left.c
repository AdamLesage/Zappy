/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** turn_left
*/

#include "server.h"

void turn_left(players_t *players, int fd)
{
    player_info_t *info = find_player(players, fd);

    if (info == NULL) {
        return;
    }
    switch (info->orientation) {
        case N:
            info->orientation = W;
            break;
        case W:
            info->orientation = S;
            break;
        case S:
            info->orientation = E;
            break;
        case E:
            info->orientation = N;
            break;
    }
}
