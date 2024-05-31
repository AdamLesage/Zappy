/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** find_player
*/

#include "server.h"

player_info_t *find_player(players_t *player, int fd)
{
    if (player == NULL) {
        return (NULL);
    }
    for (players_list_t *tmp = player->players_list; tmp != NULL;
        tmp = tmp->next) {
        if (tmp->fd == fd) {
            return (tmp->player_info);
        }
    }
    return (NULL);
}
