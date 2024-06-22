/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** forward
*/

#include "server.h"

void forward(core_t *core, int fd, char **command)
{
    if (command == NULL)
        return;
    move_player(&core->map, &core->players, fd);
    send_ppo(core, find_player(&core->players, fd));
    add_to_send_buffer(&core->network, "ok\n", fd);
}
