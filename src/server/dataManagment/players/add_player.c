/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** add_player
*/

#include "server.h"

static bool find_eggs(eggs_t *eggs, char *team_name, int *x, int *y)
{
    if (eggs == NULL) {
        return (false);
    }
    for (eggs_t *tmp = eggs; tmp != NULL; tmp = tmp->next) {
        if (strcmp(team_name, tmp->team_name) == 0) {
            *x = tmp->pos_x;
            *y = tmp->pos_y;
            return (true);
        }
    }
    return (false);
}

static inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (inventory == NULL) {
        return (NULL);
    }
    inventory->nb_deraumere = 0;
    inventory->nb_food = 10;
    inventory->nb_linemate = 0;
    inventory->nb_mendiane = 0;
    inventory->nb_phiras = 0;
    inventory->nb_sibur = 0;
    inventory->nb_thystame = 0;
    return (inventory);
}

static player_info_t *init_player_info(int fd, char *team_name,
    int pos_x, int pos_y)
{
    player_info_t *info = malloc(sizeof(player_info_t));
    int rand_number = 0;

    info->fd = fd;
    info->inventory = init_inventory();
    info->last_action = NULL;
    info->last_feed = 1260;
    info->level = 1;
    info->incantation_time = -1;
    while (rand_number == 0) {
        rand_number = rand() % 4;
    }
    info->orientation = rand_number;
    info->pos_x = pos_x;
    info->pos_y = pos_y;
    info->team_name = strdup(team_name);
    info->timer_action = 0;
    for (int i = 0; i != 10; i++)
        info->action_queue[i] = NULL;
    return info;
}

static void add_graphic_player(map_t *map, players_t *players, int fd,
    char *team_name)
{
    players_list_t *new_player = NULL;

    if (strcmp(team_name, "GRAPHIC") == 0) {
        new_player->fd = fd;
        new_player->player_info = init_player_info(fd, team_name,
            0, 0);
        new_player->next = players->players_list;
        players->players_list = new_player;
    }
}

bool add_player(map_t *map, players_t *players, int fd,
    char *team_name)
{
    players_list_t *new_player = NULL;
    int x = 0;
    int y = 0;

    if (map == NULL)
        return (false);
    add_graphic_player(map, players, fd, team_name);
    if (find_eggs(map->eggs, team_name, &x, &y) == true) {
        new_player = malloc(sizeof(players_list_t));
        remove_eggs(map, x, y, team_name);
        put_player(map, x, y);
        new_player->fd = fd;
        new_player->player_info = init_player_info(fd, team_name, x, y);
        new_player->player_info->id = players->current_id;
        players->current_id++;
        new_player->next = players->players_list;
        players->players_list = new_player;
        return (true);
    }
    return (false);
}
