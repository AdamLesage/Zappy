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
        add_to_send_buffer(&core->network, "sbp\n", fd);
        return;
    }
    for (int i = 0; i < core->arguments.nb_teams; i++) {
        add_to_send_buffer(&core->network, "tna ", fd);
        add_to_send_buffer(&core->network, core->arguments.name_teams[i], fd);
        add_to_send_buffer(&core->network, "\n", fd);
    }
}

void tna_start(core_t *core, int fd)
{
    for (int i = 0; i < core->arguments.nb_teams; i++) {
        add_to_send_buffer(&core->network, "tna ", fd);
        add_to_send_buffer(&core->network, core->arguments.name_teams[i], fd);
        add_to_send_buffer(&core->network, "\n", fd);
    }
}
