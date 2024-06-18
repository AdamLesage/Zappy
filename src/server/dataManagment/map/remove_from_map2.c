/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** remove_of_map2
*/

#include "server.h"

bool remove_mendiane(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    if (info->nb_mendiane == 0) {
        return (false);
    }
    info->nb_mendiane--;
    return (true);
}

bool remove_phiras(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    if (info->nb_phiras == 0) {
        return (false);
    }
    info->nb_phiras--;
    return (true);
}

bool remove_thystame(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);

    if (info == NULL) {
        return (false);
    }
    if (info->nb_thystame == 0) {
        return (false);
    }
    info->nb_thystame--;
    return (true);
}

static bool delete_eggs(char *team_name, map_t *map, int x, int y)
{
    eggs_t *deleted_eggs = NULL;

    for (eggs_t *tmp = map->eggs; tmp->next != NULL; tmp = tmp->next) {
        if (strcmp(tmp->next->team_name, team_name) == 0 &&
            tmp->next->pos_x == x && tmp->next->pos_y == y) {
            deleted_eggs = tmp->next;
            tmp->next = tmp->next->next;
            free(deleted_eggs->team_name);
            free(deleted_eggs);
            return (true);
        }
    }
    return (false);
}

bool remove_eggs(map_t *map, int x, int y, char *team_name)
{
    eggs_t *deleted_eggs = NULL;

    if (map == NULL || map->eggs == NULL) {
        return (false);
    }
    if (strcmp(map->eggs->team_name, team_name) == 0 &&
        map->eggs->pos_x == x && map->eggs->pos_y == y) {
        deleted_eggs = map->eggs;
        map->eggs = map->eggs->next;
        free(deleted_eggs->team_name);
        free(deleted_eggs);
        return (true);
    }
    return delete_eggs(team_name, map, x, y);
}
