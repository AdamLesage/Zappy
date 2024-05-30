/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_inventory
*/

#include "server.h"

inventory_t *get_inventory(players_t *players, int fd)
{
    player_info_t *info = find_player(players, fd);

    if (info == NULL) {
        return (NULL);
    }
    return (info->inventory);
}
