/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** check_food_players
*/

#include "server.h"

static void eat_food(player_info_t *info, players_t *players, map_t *map)
{
    if (info->last_feed == 0) {
        info->last_feed = 126;
        if (remove_from_inventory_2(info, Food) == false) {
            send_response("dead\n", info->fd);
            pdi(players, info->id);
            delete_player(map, players, info->fd);
            enw(players, -1, map->eggs);
        }
    } else {
        info->last_feed--;
    }
}

void check_food_players(core_t *core)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") != 0) {
            eat_food(tmp->player_info, &core->players, &core->map);
        }
    }
}
