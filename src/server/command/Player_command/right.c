/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** right
*/

#include "server.h"

void right(core_t *core, int fd, char **command)
{
    turn_right(&core->players, fd);
    send_response("ok\n", fd);
}