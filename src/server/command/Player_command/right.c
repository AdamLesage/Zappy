/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** right
*/

#include "server.h"

void right(core_t *core, int fd, char **command)
{
    if (command == NULL)
        return;
    turn_right(&core->players, fd);
    send_ppo(core, find_player(&core->players, fd));
    add_to_send_buffer(&core->network, "ok\n", fd);
}
