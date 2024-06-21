/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** send_command_responce
*/

#include "server.h"

void send_command_responce(network_t *network)
{
    for (client_list_t *tmp = network->client_list;
        tmp != NULL; tmp = tmp->next) {
        if (tmp->client_info->buffer_send != NULL) {
            send_response(tmp->client_info->buffer_send, tmp->client_info->fd);
            free(tmp->client_info->buffer_send);
            tmp->client_info->buffer_send = NULL;
        }
    }
}
