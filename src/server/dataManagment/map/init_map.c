/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** init_map
*/

#include "server.h"

tile_info_t *create_tile(int x, int y)
{
    tile_info_t *tile_info = malloc(sizeof(tile_info_t));

    tile_info->nb_deraumere = 0;
    tile_info->nb_linemate = 0;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 0;
    tile_info->nb_players = 0;
    tile_info->nb_sibur = 0;
    tile_info->nb_thystame = 0;
    tile_info->pos_x = x;
    tile_info->pos_y = y;
    tile_info->nb_food = 0;
    return (tile_info);
}

static tiles_list_t *add_tile(int x, int y, tiles_list_t **tiles_list,
    tiles_list_t *end)
{
    tiles_list_t *new_node = malloc(sizeof(tiles_list_t));

    if (new_node == NULL) {
        exit(84);
    }
    new_node->tile_info = create_tile(x, y);
    new_node->pos_x = x;
    new_node->pos_y = y;
    new_node->next = NULL;
    if (*tiles_list == NULL) {
        *tiles_list = new_node;
        return *tiles_list;
    } else {
        end->next = new_node;
        end = new_node;
        return (end);
    }
}

static void create_tiles_list(map_t *map)
{
    tiles_list_t *end = NULL;

    map->tiles_list = NULL;
    end = *(&map->tiles_list);
    for (int y = 0; y != map->height; y++) {
        for (int x = 0; x != map->width; x++) {
            end = add_tile(x, y, &map->tiles_list, end);
        }
    }
}

static void add_eggs_on_map(map_t *map, arguments_t *arguments)
{
    int x = 0;
    int y = 0;

    for (int i = 0; arguments->name_teams[i] != NULL; i++) {
        for (int nb = 0; nb != arguments->nb_client; nb++) {
            x = rand() % map->width;
            y = rand() % map->height;
            put_eggs(map, x, y, arguments->name_teams[i]);
        }
    }
}

static char **set_tile_array(tile_info_t *tile_info)
{
    char **array = malloc(sizeof(char *) * 9);

    array[0] = int_to_str(tile_info->pos_x);
    array[1] = int_to_str(tile_info->pos_y);
    array[2] = int_to_str(tile_info->nb_food);
    array[3] = int_to_str(tile_info->nb_linemate);
    array[4] = int_to_str(tile_info->nb_deraumere);
    array[5] = int_to_str(tile_info->nb_sibur);
    array[6] = int_to_str(tile_info->nb_mendiane);
    array[7] = int_to_str(tile_info->nb_phiras);
    array[8] = int_to_str(tile_info->nb_thystame);
    return array;
}

static int len_tile_info(tile_info_t *tile_info)
{
    char **array = set_tile_array(tile_info);
    int len = 4;

    for (int i = 0; i != 9; i++) {
        len += strlen(array[i]) + 1;
        free(array[i]);
    }
    free(array);
    return (len);
}

static char *get_tile_info(tile_info_t *tile_info)
{
    char **array = set_tile_array(tile_info);
    int len = len_tile_info(tile_info);
    char *string_tile_info = NULL;

    string_tile_info = malloc(sizeof(char) * len + 1);
    if (string_tile_info == NULL)
        exit(84);
    string_tile_info[0] = '\0';
    strcat(string_tile_info, "bct");
    for (int i = 0; i != 9; i++) {
        strcat(string_tile_info, " ");
        strcat(string_tile_info, array[i]);
        free(array[i]);
    }
    free(array);
    strcat(string_tile_info, "\n");
    string_tile_info[len] = '\0';
    return (string_tile_info);
}

char **get_map_info(map_t *map)
{
    char **map_array = malloc(sizeof(char *) * (map->height * map->width + 1));
    tiles_list_t *tmp = map->tiles_list;

    if (map_array == NULL) {
        exit(84);
    }
    for (int i = 0; tmp != NULL; i++) {
        map_array[i] = get_tile_info(tmp->tile_info);
        map_array[i + 1] = NULL;
        tmp = tmp->next;
    }
    return map_array;
}

void init_map(map_t *map, arguments_t *arguments)
{
    char **array;

    map->height = arguments->height;
    map->width = arguments->width;
    map->last_refille = 0;
    map->eggs = NULL;
    map->current_eggs_id = 0;
    create_tiles_list(map);
    add_eggs_on_map(map, arguments);
    array = get_map_info(map);
    free_array(array);
}
