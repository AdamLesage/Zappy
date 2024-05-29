/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** find_tile
*/

#include "server.h"

tile_info_t *find_tile(map_t *map, int x, int y)
{
    tiles_list_t *tmp = NULL;
    
    if (map == NULL) {
        return NULL;
    }
    tmp = map->tiles_list;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->pos_x == x && tmp->pos_y == y) {
            return tmp->tile_info;
        }
    }
    return NULL;
}
