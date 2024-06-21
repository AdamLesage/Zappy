/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** plv
*/

#include "server.h"

void plv(core_t *core, int fd, char **command)
{
    int player_id = atoi(command[1]);
    player_info_t *player_info = find_player_by_id(&core->players, player_id);

    if (len_array(command) != 2) {
        add_to_send_buffer(&core->network, "sbp\n", fd);
        return;
    }
    if (player_info == NULL) {
        add_to_send_buffer(&core->network, "sbp\n", fd);
        return;
    }
    add_to_send_buffer(&core->network, "plv ", fd);
    add_int_to_send_buffer(&core->network, player_info->id, fd);
    add_to_send_buffer(&core->network, " ", fd);
    add_int_to_send_buffer(&core->network, player_info->level, fd);
    add_to_send_buffer(&core->network, "\n", fd);
}

void plv_start(network_t *network, int fd, player_info_t *player_info)
{
    add_to_send_buffer(network, "plv ", fd);
    add_int_to_send_buffer(network, player_info->id, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, player_info->level, fd);
    add_to_send_buffer(network, "\n", fd);
}

void plv_event(network_t *network, players_t *players,
    player_info_t *player_info)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            plv_start(network, tmp->fd, player_info);
        }
    }
}
