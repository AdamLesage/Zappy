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
    send_response("ok\n", fd);
    for (players_list_t *tmp = core->players.players_list; tmp != NULL;
        tmp = tmp->next) {
        if (tmp->fd != fd &&
            strcmp(tmp->player_info->team_name, "GRAPHIC") != 0) {
            send_response("message ", tmp->fd);
            send_response_int(get_player_k(tmp->player_info, info->pos_x,
                info->pos_y, &core->arguments), tmp->fd);
            send_response(", ", tmp->fd);
            send_response(command[1], tmp->fd);
            send_response("\n", tmp->fd);
        }
    }
}
