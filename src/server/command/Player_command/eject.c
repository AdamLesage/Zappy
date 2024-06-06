/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** eject
*/

#include "server.h"

void eject(core_t *core, int fd, char **command)
{
    player_info_t *info = find_player(&core->players, fd);

    if (info == NULL || command == NULL)
        return;
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (tmp->fd != fd && tmp->player_info->pos_x == info->pos_x &&
            tmp->player_info->pos_y == info->pos_y &&
            strcmp(tmp->player_info->team_name, "GRAPHIC") != 0) {
            move_player2(&core->map, &core->players, tmp->fd,
                info->orientation);
            send_response("eject: ", tmp->fd);
            send_response_int(get_player_k(tmp->player_info,
                info->pos_x, info->pos_y, &core->arguments), tmp->fd);
            send_response("\n", tmp->fd);
        }
    }
    remove_eggs_at(&core->map, info->pos_x, info->pos_y);
    send_response("ok\n", fd);
}
