/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** move_player
*/

#include "server.h"

void check_new_pos(map_t *map, int *x, int *y)
{
    if (*y < 0) {
        *y = map->height - 1;
    }
    if (*y >= map->height) {
        *y = 0;
    }
    if (*x < 0) {
        *x = map->width - 1;
    }
    if (*x >= map->width) {
        *x = 0;
    }
}

void find_new_pos(player_info_t *info, map_t *map)
{
    switch (info->orientation) {
        case N:
            info->pos_y -= 1;
            break;
        case S:
            info->pos_y += 1;
            break;
        case W:
            info->pos_x -= 1;
            break;
        case E:
            info->pos_x += 1;
            break;
    }
    check_new_pos(map, &info->pos_x, &info->pos_y);
    put_player(map, info->pos_x, info->pos_y);
}

void move_player(map_t *map, players_t *player, int fd)
{
    player_info_t *info = find_player(player, fd);

    if (info == NULL || map == NULL) {
        return;
    }
    remove_player(map, info->pos_x, info->pos_y);
    find_new_pos(info, map);
}
