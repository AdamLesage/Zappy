/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** sgt
*/

#include "server.h"

void sgt(core_t *core, int fd, char **command)
{
    char *buff = NULL;
    int buff_size = 0;

    if (command == NULL || len_array(command) != 1) {
        send_response("sbp\n", fd);
        return;
    }
    buff_size = strlen("sgt ") + strlen(int_to_str(core->arguments.frequency))
    + strlen("\n") + 1;
    buff = malloc(sizeof(char) * buff_size);
    buff[0] = '\0';
    strcat(buff, "sgt ");
    strcat(buff, int_to_str(core->arguments.frequency));
    strcat(buff, "\n");
    send_response(buff, fd);
    free(buff);
}
