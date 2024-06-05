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
    tile_info_t *info = find_tile(map, x, y);
    eggs_t *new_eggs = NULL;

    if (info == NULL)
        return (false);
    for (eggs_t *tmp = info->eggs; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->team_name, team_name) == 0) {
            tmp->nb_eggs++;
            return true;
        }
    }
    new_eggs = malloc(sizeof(eggs_t));
    if (new_eggs == NULL)
        return (false);
    new_eggs->team_name = strdup(team_name);
    new_eggs->nb_eggs = 1;
    new_eggs->next = info->eggs;
    info->eggs = new_eggs;
    return (true);
}
