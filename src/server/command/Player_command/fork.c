/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** fork
*/

#include "server.h"

void ffork(core_t *core, int fd, char **command)
{
    player_info_t *info = find_player(&core->players, fd);

    if (command == NULL) {
        return;
    }
    put_eggs(&core->map, info->pos_x, info->pos_y, info->team_name);
    add_to_send_buffer(&core->network, "ok\n", fd);
    enw(core, info->id, core->map.eggs);
}
