/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** find_client
*/

#include "server.h"

client_t *find_client(client_t *client, int fd)
{
    if (client == NULL) {
        return (NULL);
    }
    for (client_t *tmp = client; tmp != NULL;
        tmp = tmp->next) {
        if (tmp->fd == fd) {
            return (tmp);
        }
    }
    return (NULL);
}
