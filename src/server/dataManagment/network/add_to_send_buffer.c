/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** add_to_send_buffer
*/

#include "server.h"

void add_to_send_buffer(network_t *network, char *responce, int fd)
{
    client_info_t *info = find_client(network, fd);

    if (info == NULL) {
        return;
    }
    info->buffer_send = alloc_buffer(info->buffer_send, strlen(responce));
    strcat(info->buffer_send, responce);
}

void add_int_to_send_buffer(network_t *network, int number, int fd)
{
    client_info_t *info = find_client(network, fd);
    char *str = NULL;

    if (info == NULL) {
        return;
    }
    str = int_to_str(number);
    info->buffer_send = alloc_buffer(info->buffer_send, strlen(str));
    strcat(info->buffer_send, str);
    free(str);
}
