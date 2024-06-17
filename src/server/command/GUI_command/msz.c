/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** msz
*/

#include "server.h"

char *set_msz_buff(int buff_size, char *str_width, char *str_height)
{
    char *buff = NULL;

    buff = malloc(sizeof(char) * buff_size);
    buff[0] = '\0';
    strcat(buff, "msz ");
    strcat(buff, str_width);
    strcat(buff, " ");
    strcat(buff, str_height);
    strcat(buff, "\n");
    return (buff);
}

void msz(core_t *core, int fd, char **command)
{
    char *buff = NULL;
    int buff_size = 0;
    char *str_height = int_to_str(core->map.height);
    char *str_width = int_to_str(core->map.width);

    if (command == NULL || len_array(command) != 1) {
        send_response("sbp\n", fd);
        return;
    }
    buff_size = strlen("msz ") + strlen(str_width)
        + strlen(" ") + strlen(str_height) + strlen("\n") + 1;
    buff = set_msz_buff(buff_size, str_width, str_height);
    send_response(buff, fd);
    free(buff);
    free(str_height);
    free(str_width);
}

void msz_start(core_t *core, int fd)
{
    char *buff = NULL;
    int buff_size = 0;
    char *str_height = int_to_str(core->map.height);
    char *str_width = int_to_str(core->map.width);

    buff_size = strlen("msz ") + strlen(str_width)
        + strlen(" ") + strlen(str_height) + strlen("\n") + 1;
    buff = set_msz_buff(buff_size, str_width, str_height);
    send_response(buff, fd);
    free(buff);
    free(str_height);
    free(str_width);
}
