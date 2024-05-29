/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** put_on_map
*/

#include "server.h"

bool put_food(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    info->nb_food++;
    return (true);
}

bool put_player(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    info->nb_players++;
    return (true);
}

bool put_linemate(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    info->nb_linemate++;
    return (true);
}

bool put_sibur(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    info->nb_sibur++;
    return (true);
}
