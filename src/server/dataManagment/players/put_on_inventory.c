/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** put_on_inventory
*/

#include "server.h"

bool put_on_inventory(players_t *players, enum Object object,
    int fd)
{
    inventory_t *inventory = get_inventory(players, fd);

    inventory->nb_food += (object == Food) ? 1 : 0;
    inventory->nb_linemate += (object == Linemate) ? 1 : 0;
    inventory->nb_mendiane += (object == Mendiane) ? 1 : 0;
    inventory->nb_phiras += (object == Phiras) ? 1 : 0;
    inventory->nb_sibur += (object == Sibur) ? 1 : 0;
    inventory->nb_thystame += (object == Thystame) ? 1 : 0;
    inventory->nb_deraumere += (object == Deraumere) ? 1 : 0;
    return (true);
}
