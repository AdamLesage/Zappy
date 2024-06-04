/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** look
*/

#include "server.h"

static void print_object_on_tile(map_t *map, int x, int y, int fd)
{
    tile_info_t *info = find_tile(map, x, y);

    for (int i = 0; i != info->nb_food; i++)
        send_response(" food", fd);
    for (int i = 0; i != info->nb_deraumere; i++)
        send_response(" deraumere", fd);
    for (int i = 0; i != info->nb_linemate; i++)
        send_response(" linemate", fd);
    for (int i = 0; i != info->nb_mendiane; i++)
        send_response(" mendiane", fd);
    for (int i = 0; i != info->nb_phiras; i++)
        send_response(" phiras", fd);
    for (int i = 0; i != info->nb_players; i++)
        send_response(" player", fd);
    for (int i = 0; i != info->nb_sibur; i++)
        send_response(" sibur", fd);
    for (int i = 0; i != info->nb_thystame; i++)
        send_response(" thystame", fd);
}

static int *get_look_orientation(enum Orientation orientation)
{
    int *orientation_x_y = malloc(sizeof(int) * 2);

    orientation_x_y[0] = 0;
    orientation_x_y[1] = 0;
    if (orientation == N)
        orientation_x_y[0] = -1;
    if (orientation == S)
        orientation_x_y[0] = 1;
    if (orientation == W)
        orientation_x_y[1] = -1;
    if (orientation == E)
        orientation_x_y[1] = 1;
    return (orientation_x_y);
}

static void check_pos_tile(map_t *map, int *y, int *x)
{
    if (*y < 0) {
        *y = map->height - abs(*y);
    }
    if (*x < 0) {
        *x = map->width - abs(*x);
    }
}

static void print_look_on_tile(core_t *core, int level,
    int *orientation_x_y, int fd)
{
    int x = 0;
    int y = 0;
    player_info_t *info = find_player(&core->players, fd);

    for (int i = level * -1; i != level + 1; i++) {
        x = (orientation_x_y[1] == 0) ? info->pos_x + i + level *
            orientation_x_y[1] : info->pos_x + level * orientation_x_y[1];
        y = (orientation_x_y[1] == 0) ? info->pos_y + level *
            orientation_x_y[0] : info->pos_y + i + level * orientation_x_y[0];
        check_pos_tile(&core->map, &y, &x);
        print_object_on_tile(&core->map, x, y, fd);
        if (!(level == 3 && i == level))
            send_response(",", fd);
    }
}

void look(core_t *core, int fd, char **command)
{
    player_info_t *info = find_player(&core->players, fd);
    int *orientation_x_y = get_look_orientation(info->orientation);
    int x = 0;
    int y = 0;

    send_response("[", fd);
    for (int level = 0; level != 3 + 1; level++) {
        print_look_on_tile(core, level, orientation_x_y, fd);
    }
    send_response(" ]\n", fd);
    free(orientation_x_y);
}
