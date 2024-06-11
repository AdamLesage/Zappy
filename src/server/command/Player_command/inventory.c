/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** inventory
*/

#include "server.h"

void inventory(core_t *core, int fd, char **command)
{
    inventory_t *inventory = get_inventory(&core->players, fd);

    if (command == NULL)
        return;
    send_response("[ food ", fd);
    send_response_int(inventory->nb_food, fd);
    send_response(", linemate ", fd);
    send_response_int(inventory->nb_linemate, fd);
    send_response(", deraumere ", fd);
    send_response_int(inventory->nb_deraumere, fd);
    send_response(", sibur ", fd);
    send_response_int(inventory->nb_sibur, fd);
    send_response(", mendiane ", fd);
    send_response_int(inventory->nb_mendiane, fd);
    send_response(", phiras ", fd);
    send_response_int(inventory->nb_phiras, fd);
    send_response(", thystame ", fd);
    send_response_int(inventory->nb_thystame, fd);
    send_response(" ]\n", fd);
}
