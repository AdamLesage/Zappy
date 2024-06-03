/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** msz
*/

#include "server.h"

void msz(core_t *core, int fd, char **command)
{
    char *buff = NULL;

    if (len_array(command) != 1) {
        send_response("sbp\n", fd);
        return;
    }
    buff = strcat("msz ", int_to_str(core->map.width));
    buff = strcat(buff, " ");
    buff = strcat(buff, int_to_str(core->map.height));
    buff = strcat(buff, "\n");
    send_response(buff, fd);
    free(buff);
}
