/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pic
*/

#include "server.h"

static void send_pic_info(network_t *network, incantation_info_t *info, int fd)
{
    add_to_send_buffer(network, "pic ", fd);
    add_int_to_send_buffer(network, info->pos_x, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, info->pos_y, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, info->incantation_level, fd);
    for (int i = 0; info->ids[i] != -1; i ++) {
        add_to_send_buffer(network, " ", fd);
        add_int_to_send_buffer(network, info->ids[i], fd);
    }
    add_to_send_buffer(network, "\n", fd);
}

void pic(core_t *core, incantation_info_t *info)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            send_pic_info(&core->network, info, tmp->fd);
        }
    }
}
