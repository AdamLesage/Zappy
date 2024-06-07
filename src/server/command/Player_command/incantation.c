/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** incantation
*/

#include "server.h"

void incantation(core_t *core, int fd, char **command)
{
    player_info_t *player_info = find_player(&core->players, fd);
    tile_info_t *tile_info = find_tile(&core->map, player_info->pos_x,
        player_info->pos_y);

    if (incantation_is_valide(tile_info, core->players.players_list,
        player_info->level)) {
        incantation_destroy_stone(tile_info, player_info->level);
        player_info->level++;
        send_response("Current level: ", fd);
        send_response_int(player_info->level, fd);
        send_response("\n", fd);
    } else {
        send_response("ko\n", fd);
    }
}
