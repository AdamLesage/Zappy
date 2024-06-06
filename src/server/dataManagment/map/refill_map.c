/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** refill_map
*/

#include "server.h"

static inventory_t *get_nb_object(tiles_list_t *tile)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    inventory->nb_deraumere = 0;
    inventory->nb_food = 0;
    inventory->nb_linemate = 0;
    inventory->nb_mendiane = 0;
    inventory->nb_phiras = 0;
    inventory->nb_sibur = 0;
    inventory->nb_thystame = 0;
    for (tiles_list_t *tmp = tile; tmp != NULL; tmp = tmp->next) {
        inventory->nb_deraumere += tmp->tile_info->nb_deraumere;
        inventory->nb_food += tmp->tile_info->nb_food;
        inventory->nb_linemate += tmp->tile_info->nb_linemate;
        inventory->nb_mendiane += tmp->tile_info->nb_mendiane;
        inventory->nb_phiras += tmp->tile_info->nb_phiras;
        inventory->nb_sibur += tmp->tile_info->nb_sibur;
        inventory->nb_thystame += tmp->tile_info->nb_thystame;
    }
    return (inventory);
}

static void reffil_object(map_t *map, int nb_object, float density,
    bool put(map_t *, int, int))
{
    int x = 0;
    int y = 0;
    float nb_object_max = map->height * map->width * density;

    for (int i = (int)(nb_object_max - nb_object); i > 0; i--) {
        x = rand() % map->width;
        y = rand() % map->height;
        put(map, x, y);
    }
}

void refill_map(map_t *map)
{
    inventory_t *inventory = get_nb_object(map->tiles_list);

    reffil_object(map, inventory->nb_food, 0.5, &put_food);
    reffil_object(map, inventory->nb_linemate, 0.3, &put_linemate);
    reffil_object(map, inventory->nb_deraumere, 0.15, &put_deraumere);
    reffil_object(map, inventory->nb_sibur, 0.1, &put_sibur);
    reffil_object(map, inventory->nb_mendiane, 0.1, &put_mendiane);
    reffil_object(map, inventory->nb_phiras, 0.08, &put_phiras);
    reffil_object(map, inventory->nb_thystame, 0.05, &put_thystame);
    map->last_refille = 20;
    free(inventory);
}