/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** remove_of_map
*/

#include "server.h"

bool remove_food(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    if (info->nb_food == 0) {
        return (false);
    }
    info->nb_food--;
    return (true);
}

bool remove_player(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    if (info->nb_players == 0) {
        return (false);
    }
    info->nb_players--;
    return (true);
}

bool remove_linemate(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    if (info->nb_linemate == 0) {
        return (false);
    }
    info->nb_linemate--;
    return (true);
}

bool remove_sibur(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    if (info->nb_sibur == 0) {
        return (false);
    }
    info->nb_sibur--;
    return (true);
}

bool remove_deraumere(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    if (info->nb_deraumere == 0) {
        return (false);
    }
    info->nb_deraumere--;
    return (true);
}
