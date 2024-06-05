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

static bool delete_eggs(tile_info_t *info, char *team_name)
{
    eggs_t *deleted_eggs = NULL;

    for (eggs_t *tmp = info->eggs; tmp->next != NULL; tmp = tmp->next) {
        if (strcmp(tmp->next->team_name, team_name) == 0 &&
            tmp->next->nb_eggs == 1) {
            deleted_eggs = tmp->next;
            tmp->next = tmp->next->next;
            free(deleted_eggs);
            return (true);
        }
        if (strcmp(tmp->next->team_name, team_name) == 0 &&
            tmp->next->nb_eggs != 1) {
            tmp->next->nb_eggs--;
            return (true);
        }
    }
    return (false);
}

bool remove_eggs(map_t *map, int x, int y, char *team_name)
{
    tile_info_t *info = find_tile(map, x, y);
    eggs_t *deleted_eggs = NULL;

    if (info == NULL || info->eggs == NULL)
        return (false);
    if (strcmp(info->eggs->team_name, team_name) == 0) {
        if (info->eggs->nb_eggs == 1) {
            deleted_eggs = info->eggs;
            info->eggs = info->eggs->next;
            free(deleted_eggs);
            return true;
        } else {
            info->eggs->nb_eggs--;
            return true;
        }
    }
    return delete_eggs(info, team_name);
}
