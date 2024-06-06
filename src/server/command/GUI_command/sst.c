/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** sst
*/

#include "server.h"

void sst(core_t *core, int fd, char **command)
{
    char *buff = NULL;
    int buff_size = 0;
    int new_frequency = 0;

    if (len_array(command) != 2) {
        send_response("sbp\n", fd);
        return;
    }
    new_frequency = atoi(command[1]);
    core->arguments.frequency = new_frequency;
    buff_size = strlen("sst ") + strlen(command[1]) + strlen("\n") + 1;
    buff = malloc(sizeof(char) * buff_size);
    buff[0] = '\0';
    strcat(buff, "sst ");
    strcat(buff, command[1]);
    strcat(buff, "\n");
    send_response(buff, fd);
    free(buff);
}
