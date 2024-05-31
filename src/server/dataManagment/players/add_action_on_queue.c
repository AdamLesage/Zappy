/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** add_action_on_queue
*/

#include "server.h"

void add_action_in_queue(players_t *players, int fd, char *action)
{
    player_info_t *info = find_player(players, fd);

    if (info == NULL) {
        return;
    }
    for (int i = 0; i != 10; i++) {
        if (info->action_queue[i] == NULL) {
            info->action_queue[i] = strdup(action);
            return;
        }
    }
}
