/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** bct
*/

#include "server.h"

tiles_list_t *get_current_tile(core_t *core, int x, int y)
{
    tiles_list_t *current_tile = core->map.tiles_list;

    while (current_tile != NULL) {
        if (current_tile->pos_x == x && current_tile->pos_y == y) {
            return current_tile;
        }
        current_tile = current_tile->next;
    }
    return NULL;
}

void bct(core_t *core, int fd, char **command)
{
    int x = atoi(command[1]);
    int y = atoi(command[2]);
    tiles_list_t *current_tile = get_current_tile(core, x, y);

    if (len_array(command) != 3) {
        add_to_send_buffer(&core->network, "sbp\n", fd);
        return;
    }
    if (x < 0 || x >= core->map.width || y < 0 || y >= core->map.height) {
        add_to_send_buffer(&core->network, "sbp\n", fd);
        return;
    }
    if (current_tile != NULL) {
        bct_two(core, fd, current_tile);
    }
}

void bct_two(core_t *core, int fd, tiles_list_t *current_tile)
{
    tile_info_t *tile_info = current_tile->tile_info;

    add_to_send_buffer(&core->network, "bct ", fd);
    add_int_to_send_buffer(&core->network, current_tile->pos_x, fd);
    add_to_send_buffer(&core->network, " ", fd);
    add_int_to_send_buffer(&core->network, current_tile->pos_y, fd);
    add_to_send_buffer(&core->network, " ", fd);
    add_int_to_send_buffer(&core->network, tile_info->nb_food, fd);
    add_to_send_buffer(&core->network, " ", fd);
    add_int_to_send_buffer(&core->network, tile_info->nb_linemate, fd);
    add_to_send_buffer(&core->network, " ", fd);
    add_int_to_send_buffer(&core->network, tile_info->nb_deraumere, fd);
    add_to_send_buffer(&core->network, " ", fd);
    add_int_to_send_buffer(&core->network, tile_info->nb_sibur, fd);
    add_to_send_buffer(&core->network, " ", fd);
    add_int_to_send_buffer(&core->network, tile_info->nb_mendiane, fd);
    add_to_send_buffer(&core->network, " ", fd);
    bct_three(core, fd, current_tile);
}

void bct_three(core_t *core, int fd, tiles_list_t *current_tile)
{
    tile_info_t *tile_info = current_tile->tile_info;

    add_int_to_send_buffer(&core->network, tile_info->nb_phiras, fd);
    add_to_send_buffer(&core->network, " ", fd);
    add_int_to_send_buffer(&core->network, tile_info->nb_thystame, fd);
    add_to_send_buffer(&core->network, "\n", fd);
}

void bct_event(core_t *core, int x, int y)
{
    tiles_list_t *tiles_list = get_current_tile(core, x, y);

    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            bct_two(core, tmp->fd, tiles_list);
        }
    }
}
