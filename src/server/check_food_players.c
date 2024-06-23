/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** check_food_players
*/

#include "server.h"

/**
 * @brief Check if a player can eat
 *
 * @param info
 * @param core
 * @return true
 * @return false
 */
static bool eat_food(player_info_t *info, core_t *core)
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
            return (true);
        }
        pin_event(&core->network, &core->players, info);
    } else {
        info->last_feed--;
    }
    return (false);
}

/**
 * @brief Check if a player can eat
 *
 * @param core
 */
void check_food_players(core_t *core)
{
    bool is_deleted = false;

    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        is_deleted = false;
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") != 0) {
            is_deleted = eat_food(tmp->player_info, core);
        }
        if (is_deleted == true) {
            check_food_players(core);
            return;
        }
    }
}
