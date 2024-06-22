/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** add_client
*/

#include "server.h"

bool add_client_on_network(network_t *network, int fd)
{
    client_list_t *new_client = NULL;

    new_client = malloc(sizeof(network_t));
    if (new_client == NULL)
        return (false);
    new_client->fd = fd;
    new_client->client_info = malloc(sizeof(client_info_t));
    new_client->client_info->fd = fd;
    new_client->client_info->buffer_read = NULL;
    new_client->client_info->buffer_send = NULL;
    new_client->next = network->client_list;
    network->client_list = new_client;
    return (true);
}
