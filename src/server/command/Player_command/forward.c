/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** forward
*/

#include "server.h"

void forward(core_t *core, int fd, char **command)
{
    move_player(&core->map, &core->players, fd);
    send_response("ok\n", fd);
}
