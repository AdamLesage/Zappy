/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** left
*/

#include "server.h"

void left(core_t *core, int fd, char **command)
{
    if (command == NULL)
        return;
    turn_left(&core->players, fd);
    send_response("ok\n", fd);
}
