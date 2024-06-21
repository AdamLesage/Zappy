/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** check_food_players
*/

#include "server.h"

static void eat_food(player_info_t *info, core_t *core)
{
    if (info->last_feed == 0) {
        info->last_feed = 126;
        if (remove_from_inventory_2(info, Food) == false) {
            add_to_send_buffer(&core->network, "dead\n", info->fd);
            close(info->fd);
            FD_CLR(info->fd, &core->network.select_info.rfds);
            pdi(core, info->id);
            delete_player(&core->map, &core->players, info->fd);
            enw(core, -1, core->map.eggs);
            return;
        }
        pin_event(&core->network, &core->players, info);
    } else {
        info->last_feed--;
    }
}

void check_food_players(core_t *core)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") != 0) {
            eat_food(tmp->player_info, core);
        }
    }
}
