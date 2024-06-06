/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** bct
*/

#include "server.h"

void bct(core_t *core, int fd, char **command)
{
    int x = atoi(command[1]);
    int y = atoi(command[2]);

    if (len_array(command) != 3) {
        send_response("sbp\n", fd);
        return;
    }
    if (x < 0 || x >= core->map.width || y < 0 || y >= core->map.height) {
        send_response("sbp\n", fd);
        return;
    }
    tiles_list_t *current_tile = core->map.tiles_list;
    if (current_tile != NULL) {
        bct_two(core, fd, current_tile);
    }
}

void bct_two(core_t *core, int fd, tiles_list_t *current_tile)
{
    tile_info_t *tile_info = current_tile->tile_info;

    send_response("bct ", fd);
    send_response_int(current_tile->pos_x, fd);
    send_response(" ", fd);
    send_response_int(current_tile->pos_y, fd);
    send_response(" ", fd);
    send_response_int(tile_info->nb_linemate, fd);
    send_response(" ", fd);
    send_response_int(tile_info->nb_deraumere, fd);
    send_response(" ", fd);
    send_response_int(tile_info->nb_sibur, fd);
    send_response(" ", fd);
    send_response_int(tile_info->nb_mendiane, fd);
    send_response(" ", fd);
    send_response_int(tile_info->nb_phiras, fd);
    send_response(" ", fd);
    bct_three(core, fd, current_tile);
}

void bct_three(core_t *core, int fd, tiles_list_t *current_tile)
{
    tile_info_t *tile_info = current_tile->tile_info;

    send_response_int(tile_info->nb_thystame, fd);
    send_response(" ", fd);
    send_response_int(tile_info->nb_food, fd);
    send_response(" ", fd);
}
