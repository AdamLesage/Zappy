/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** add_client
*/

#include "server.h"

bool add_client(core_t *core, int fd)
{
    client_t *new_client = NULL;

    new_client = malloc(sizeof(client_t));
    if (new_client == NULL)
        return (false);
    new_client->fd = fd;
    new_client->command = NULL;
    new_client->next = core->client;
    core->client = new_client;
    return (true);
}
