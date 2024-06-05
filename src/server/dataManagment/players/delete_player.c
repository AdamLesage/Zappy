/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** delete_player
*/

#include "server.h"

static bool delete_player2(map_t *map, players_t *players, int fd)
{
    players_list_t *deleted_player = NULL;

    for (players_list_t *tmp = players->players_list; tmp->next != NULL;
        tmp = tmp->next) {
        if (tmp->next->fd == fd) {
            deleted_player = tmp->next;
            tmp->next = tmp->next->next;
            remove_player(map, deleted_player->player_info->pos_x,
                deleted_player->player_info->pos_y);
            put_eggs(map, deleted_player->player_info->pos_x,
                deleted_player->player_info->pos_y,
                deleted_player->player_info->team_name);
            free(deleted_player);
            return (true);
        }
    }
    return (false);
}

bool delete_player(map_t *map, players_t *players, int fd)
{
    player_info_t *player_info = find_player(players, fd);
    players_list_t *deleted_player = NULL;

    if (player_info == NULL) {
        return (false);
    }
    if (players->players_list->fd == fd) {
        deleted_player = players->players_list;
        players->players_list = players->players_list->next;
        remove_player(map, player_info->pos_x, player_info->pos_y);
        put_eggs(map, player_info->pos_x, player_info->pos_y,
            player_info->team_name);
        free(deleted_player);
        return true;
    }
    return delete_player2(map, players, fd);
}
