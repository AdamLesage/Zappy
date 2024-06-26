/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** find_tile
*/

#include "server.h"

/**
 * @brief Find a tile
 *
 * @param map The map
 * @param x The x
 * @param y The y
 * @return tile_info_t* The tile
 */
tile_info_t *find_tile(map_t *map, int x, int y)
{
    tiles_list_t *tmp = NULL;

    if (map == NULL || x < 0 || y < 0) {
        return NULL;
    }
    x = x % map->width;
    y = y % map->height;
    tmp = map->tiles_list;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->pos_x == x && tmp->pos_y == y) {
            return tmp->tile_info;
        }
    }
    return NULL;
}
