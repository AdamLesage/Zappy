/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** mtc
*/

#include "server.h"

void mct(core_t *core, int fd, char **command)
{
    tiles_list_t *current_tile = core->map.tiles_list;

    if (len_array(command) != 1) {
        send_response("sbp\n", fd);
        return;
    }
    while (current_tile != NULL) {
        bct_two(fd, current_tile);
        current_tile = current_tile->next;
    }
}

void mct_start(core_t *core, int fd)
{
    tiles_list_t *current_tile = core->map.tiles_list;

    while (current_tile != NULL) {
        bct_two(fd, current_tile);
        current_tile = current_tile->next;
    }
}

void mct_event(core_t *core)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            mct_start(core, tmp->fd);
        }
    }
}
