/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ppo
*/

#include "server.h"

void ppo(core_t *core, int fd, char **command)
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
    add_to_send_buffer(&core->network, "ppo ", fd);
    add_int_to_send_buffer(&core->network, player_info->id, fd);
    add_to_send_buffer(&core->network, " ", fd);
    add_int_to_send_buffer(&core->network, player_info->pos_x, fd);
    add_to_send_buffer(&core->network, " ", fd);
    add_int_to_send_buffer(&core->network, player_info->pos_y, fd);
    add_to_send_buffer(&core->network, " ", fd);
    add_int_to_send_buffer(&core->network, player_info->orientation, fd);
    add_to_send_buffer(&core->network, "\n", fd);
}

void ppo_event(network_t *network, int fd, player_info_t *player_info)
{
    if (player_info == NULL) {
        add_to_send_buffer(network, "sbp\n", fd);
        return;
    }
    add_to_send_buffer(network, "ppo ", fd);
    add_int_to_send_buffer(network, player_info->id, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, player_info->pos_x, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, player_info->pos_y, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, player_info->orientation, fd);
    add_to_send_buffer(network, "\n", fd);
}

void send_ppo(core_t *core, player_info_t *player_info)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            ppo_event(&core->network, tmp->fd, player_info);
        }
    }
}
