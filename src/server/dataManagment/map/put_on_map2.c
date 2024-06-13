/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** put_on_map2
*/

#include "server.h"

bool put_mendiane(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    info->nb_mendiane++;
    return (true);
}

bool put_phiras(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    info->nb_phiras++;
    return (true);
}

bool put_thystame(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    info->nb_thystame++;
    return (true);
}

bool put_eggs(map_t *map, int x, int y, char *team_name)
{
    eggs_t *new_eggs = NULL;

    new_eggs = malloc(sizeof(eggs_t));
    if (new_eggs == NULL || x < 0 || y < 0)
        return (false);
    new_eggs->team_name = strdup(team_name);
    new_eggs->pos_x = x;
    new_eggs->pos_y = y;
    new_eggs->egg_id = map->current_eggs_id;
    new_eggs->next = map->eggs;
    map->eggs = new_eggs;
    map->current_eggs_id++;
    return (true);
}
