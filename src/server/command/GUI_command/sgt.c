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
    char *str_frequency = NULL;

    if (command == NULL || len_array(command) != 1) {
        send_response("sbp\n", fd);
        return;
    }
    str_frequency = int_to_str(core->arguments.frequency);
    buff_size = strlen("sgt ") + strlen(str_frequency)
    + strlen("\n") + 1;
    buff = malloc(sizeof(char) * buff_size);
    buff[0] = '\0';
    strcat(buff, "sgt ");
    strcat(buff, str_frequency);
    strcat(buff, "\n");
    add_to_send_buffer(&core->network, buff, fd);
    free(buff);
    free(str_frequency);
}

void sgt_start(core_t *core, int fd)
{
    char *buff = NULL;
    int buff_size = 0;
    char *str_frequency = NULL;

    str_frequency = int_to_str(core->arguments.frequency);
    buff_size = strlen("sgt ") + strlen(str_frequency)
    + strlen("\n") + 1;
    buff = malloc(sizeof(char) * buff_size);
    buff[0] = '\0';
    strcat(buff, "sgt ");
    strcat(buff, str_frequency);
    strcat(buff, "\n");
    add_to_send_buffer(&core->network, buff, fd);
    free(buff);
    free(str_frequency);
}
