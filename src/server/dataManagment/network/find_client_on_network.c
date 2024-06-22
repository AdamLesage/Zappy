/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** find_client
*/

#include "server.h"

client_info_t *find_client(network_t *network, int fd)
{
    if (network == NULL || network->client_list == NULL) {
        return (NULL);
    }
    for (client_list_t *tmp = network->client_list; tmp != NULL;
        tmp = tmp->next) {
        if (tmp->fd == fd) {
            return (tmp->client_info);
        }
    }
    return (NULL);
}
