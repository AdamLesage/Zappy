/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** delete_client
*/

#include "server.h"

static bool delete_client2(core_t *core, int fd)
{
    client_t *deleted_client = NULL;

    for (client_t *tmp = core->client; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->fd == fd) {
            deleted_client = core->client;
            core->client = core->client->next;
            free(deleted_client->command);
            free(deleted_client);
            return (true);
        }
    }
    return (false);
}

bool delete_client(core_t *core, int fd)
{
    client_t *deleted_client = NULL;

    if (core == NULL || core->client == NULL) {
        return (false);
    }
    if (core->client->fd == fd) {
        deleted_client = core->client;
        core->client = core->client->next;
        free(deleted_client->command);
        free(deleted_client);
        return (true);
    }
    return delete_client2(core, fd);
}
