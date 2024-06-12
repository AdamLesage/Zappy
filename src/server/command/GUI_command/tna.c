/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tna
*/

#include "server.h"

void tna(core_t *core, int fd, char **command)
{
    if (len_array(command) != 1) {
        send_response("sbp\n", fd);
        return;
    }
    for (int i = 0; i < core->arguments.nb_teams; i++) {
        send_response("tna ", fd);
        send_response(core->arguments.name_teams[i], fd);
        send_response("\n", fd);
    }
}

void tna_start(core_t *core, int fd)
{
    for (int i = 0; i < core->arguments.nb_teams; i++) {
        send_response("tna ", fd);
        send_response(core->arguments.name_teams[i], fd);
        send_response("\n", fd);
    }
}
