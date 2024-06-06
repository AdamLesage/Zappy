/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** remove_from_inventory
*/


#include "server.h"

static bool remove_from_inventory2(inventory_t *inventory, enum Object object)
{
    if (inventory->nb_phiras == 0 && object == Phiras)
        return (false);
    inventory->nb_phiras -= (object == Phiras) ? 1 : 0;
    if (inventory->nb_sibur == 0 && object == Sibur)
        return (false);
    inventory->nb_sibur -= (object == Sibur) ? 1 : 0;
    if (inventory->nb_thystame == 0 && object == Thystame)
        return (false);
    inventory->nb_thystame -= (object == Thystame) ? 1 : 0;
    if (inventory->nb_deraumere == 0 && object == Deraumere)
        return (false);
    inventory->nb_deraumere -= (object == Deraumere) ? 1 : 0;
    return (true);
}

bool remove_from_inventory(players_t *players, enum Object object,
    int fd)
{
    inventory_t *inventory = get_inventory(players, fd);

    if (object == None) {
        return (false);
    }
    if (inventory->nb_food == 0 && object == Food)
        return (false);
    inventory->nb_food -= (object == Food) ? 1 : 0;
    if (inventory->nb_linemate == 0 && object == Linemate)
        return (false);
    inventory->nb_linemate -= (object == Linemate) ? 1 : 0;
    if (inventory->nb_mendiane == 0 && object == Mendiane)
        return (false);
    inventory->nb_mendiane -= (object == Mendiane) ? 1 : 0;
    return (remove_from_inventory2(inventory, object));
}
