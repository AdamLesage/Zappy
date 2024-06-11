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
        send_response("sbp\n", fd);
        return;
    }
    if (player_info == NULL) {
        send_response("sbp\n", fd);
        return;
    }
    send_response("ppo ", fd);
    send_response_int(player_info->id, fd);
    send_response(" ", fd);
    send_response_int(player_info->pos_x, fd);
    send_response(" ", fd);
    send_response_int(player_info->pos_y, fd);
    send_response(" ", fd);
    send_response_int(player_info->orientation, fd);
    send_response("\n", fd);
}

void ppo_event(int fd, player_info_t *player_info)
{
    if (player_info == NULL) {
        send_response("sbp\n", fd);
        return;
    }
    send_response("ppo ", fd);
    send_response_int(player_info->id, fd);
    send_response(" ", fd);
    send_response_int(player_info->pos_x, fd);
    send_response(" ", fd);
    send_response_int(player_info->pos_y, fd);
    send_response(" ", fd);
    send_response_int(player_info->orientation, fd);
    send_response("\n", fd);
}

void send_ppo(core_t *core, player_info_t *player_info)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            ppo_event(tmp->fd, player_info);
        }
    }
}
