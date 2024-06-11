/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** left
*/

#include "server.h"

void left(core_t *core, int fd, char **command)
{
    turn_left(&core->players, fd);
    send_response("ok\n", fd);
}
