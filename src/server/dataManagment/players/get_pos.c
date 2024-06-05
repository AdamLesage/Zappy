/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_pos
*/

#include "server.h"

int *get_pos(players_t *players, int fd)
{
    player_info_t *info = find_player(players, fd);
    int *pos = malloc(sizeof(int) * 2);

    if (info == NULL || pos == NULL) {
        return (NULL);
    }
    pos[0] = info->pos_x;
    pos[1] = info->pos_y;
    return (pos);
}
