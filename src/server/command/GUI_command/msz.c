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
    int buff_size = 0;

    if (command == NULL || len_array(command) != 1) {
        send_response("sbp\n", fd);
        return;
    }
    buff_size = strlen("msz ") + strlen(int_to_str(core->map.width))
    + strlen(" ") + strlen(int_to_str(core->map.height)) + strlen("\n") + 1;
    buff = malloc(sizeof(char) * buff_size);
    buff[0] = '\0';
    strcat(buff, "msz ");
    strcat(buff, int_to_str(core->map.width));
    strcat(buff, " ");
    strcat(buff, int_to_str(core->map.height));
    strcat(buff, "\n");
    send_response(buff, fd);
    free(buff);
}

void msz_start(core_t *core, int fd)
{
    char *buff = NULL;
    int buff_size = 0;

    buff_size = strlen("msz ") + strlen(int_to_str(core->map.width))
    + strlen(" ") + strlen(int_to_str(core->map.height)) + strlen("\n") + 1;
    buff = malloc(sizeof(char) * buff_size);
    buff[0] = '\0';
    strcat(buff, "msz ");
    strcat(buff, int_to_str(core->map.width));
    strcat(buff, " ");
    strcat(buff, int_to_str(core->map.height));
    strcat(buff, "\n");
    send_response(buff, fd);
    free(buff);
}
