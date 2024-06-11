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
        send_response("sbp\n", fd);
        return;
    }
    if (player_info == NULL) {
        send_response("sbp\n", fd);
        return;
    }
    send_response("plv ", fd);
    send_response_int(player_info->id, fd);
    send_response(" ", fd);
    send_response_int(player_info->level, fd);
    send_response("\n", fd);
}

void plv_start(int fd, player_info_t *player_info)
{
    send_response("plv ", fd);
    send_response_int(player_info->id, fd);
    send_response(" ", fd);
    send_response_int(player_info->level, fd);
    send_response("\n", fd);
}
