/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** delete_client
*/

#include "server.h"

static void free_client(client_list_t *deleted_client)
{
    if (deleted_client->client_info->buffer_read != NULL) {
        free(deleted_client->client_info->buffer_read);
    }
    if (deleted_client->client_info->buffer_send != NULL) {
        free(deleted_client->client_info->buffer_send);
    }
    free(deleted_client->client_info);
    free(deleted_client);
}

static bool delete_client_of_network2(network_t *network, int fd)
{
    client_list_t *deleted_client = NULL;

    for (client_list_t *tmp = network->client_list;
        tmp->next != NULL; tmp = tmp->next) {
        if (tmp->fd == fd) {
            deleted_client = tmp->next;
            tmp->next = tmp->next->next;
            free_client(deleted_client);
            return (true);
        }
    }
    return (false);
}

bool delete_client_of_network(network_t *network, int fd)
{
    client_list_t *deleted_client = NULL;

    if (network == NULL || network->client_list == NULL) {
        return (false);
    }
    if (network->client_list->fd == fd) {
        deleted_client = network->client_list;
        network->client_list = network->client_list->next;
        free_client(deleted_client);
        return (true);
    }
    return delete_client_of_network2(network, fd);
}
