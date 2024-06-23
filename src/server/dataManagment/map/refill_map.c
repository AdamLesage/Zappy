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

static void reffil_object(core_t *core, int nb_object, float density,
    bool put(map_t *, int, int))
{
    int x = 0;
    int y = 0;
    float nb_object_max = core->map.height * core->map.width * density;

    for (int i = (int)(nb_object_max - nb_object); i > 0; i--) {
        x = rand() % core->map.width;
        y = rand() % core->map.height;
        put(&core->map, x, y);
        bct_event(core, x, y);
    }
}

void refill_map(core_t *core)
{
    inventory_t *inventory = get_nb_object(core->map.tiles_list);

    reffil_object(core, inventory->nb_food, 0.5, &put_food);
    reffil_object(core, inventory->nb_linemate, 0.3, &put_linemate);
    reffil_object(core, inventory->nb_deraumere, 0.15, &put_deraumere);
    reffil_object(core, inventory->nb_sibur, 0.1, &put_sibur);
    reffil_object(core, inventory->nb_mendiane, 0.1, &put_mendiane);
    reffil_object(core, inventory->nb_phiras, 0.08, &put_phiras);
    reffil_object(core, inventory->nb_thystame, 0.05, &put_thystame);
    core->map.last_refille = 20;
    free(inventory);
}
