/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_action_in_queue
*/

#include "server.h"

char *get_action_in_queue(players_t *players, int fd)
{
    player_info_t *info = find_player(players, fd);
    char *action = NULL;
    int i = 0;

    if (info == NULL)
        return (NULL);
    if (info->action_queue[0] == NULL)
        return (NULL);
    action = strdup(info->action_queue[0]);
    free(info->action_queue[0]);
    info->action_queue[0] = NULL;
    for (; i != 9 && info->action_queue[i + 1] != NULL; i++) {
        info->action_queue[i] = info->action_queue[i + 1];
        if (info->action_queue[i + 1] == NULL)
            info->action_queue[i] = NULL;
    }
    if (i <= 9)
        info->action_queue[i] = NULL;
    return (action);
}
