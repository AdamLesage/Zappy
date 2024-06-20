/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** broadcast
*/

#include "server.h"

void broadcast(core_t *core, int fd, char **command)
{
    player_info_t *info = find_player(&core->players, fd);

    if (command == NULL) {
        return;
    }
    add_to_send_buffer(&core->network, "ok\n", fd);
    for (players_list_t *tmp = core->players.players_list; tmp != NULL;
        tmp = tmp->next) {
        if (tmp->fd != fd &&
            strcmp(tmp->player_info->team_name, "GRAPHIC") != 0) {
            add_to_send_buffer(&core->network, "message ", tmp->fd);
            add_int_to_send_buffer(&core->network,
                get_player_k(tmp->player_info, info->pos_x,
                info->pos_y, &core->arguments), tmp->fd);
            add_to_send_buffer(&core->network, ", ", tmp->fd);
            add_to_send_buffer(&core->network, command[1], tmp->fd);
            add_to_send_buffer(&core->network, "\n", tmp->fd);
        }
        pbc(&core->players, info->id, command[1]);
    }
}
