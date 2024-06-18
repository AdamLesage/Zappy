/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** look
*/

#include "server.h"

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

static int get_len_object_on_tile(map_t *map, int x, int y)
{
    tile_info_t *info = find_tile(map, x, y);
    int len = 0;

    for (int i = 0; i != info->nb_food; i++)
        len += strlen(" food");
    for (int i = 0; i != info->nb_deraumere; i++)
        len += strlen(" deraumere");
    for (int i = 0; i != info->nb_linemate; i++)
        len += strlen(" linemate");
    for (int i = 0; i != info->nb_mendiane; i++)
        len += strlen(" mendiane");
    for (int i = 0; i != info->nb_phiras; i++)
        len += strlen(" phiras");
    for (int i = 0; i != info->nb_players; i++)
        len += strlen(" player");
    for (int i = 0; i != info->nb_sibur; i++)
        len += strlen(" sibur");
    for (int i = 0; i != info->nb_thystame; i++)
        len += strlen(" thystame");
    return (len);
}

static void get_tile_pos(int *x, int *y, int i, look_info_t *look_info)
{
    *x = (look_info->look_orientation[1] == 0) ?
        look_info->player_info->pos_x + i + look_info->level
        * look_info->look_orientation[1] : look_info->player_info->pos_x
        + look_info->level * look_info->look_orientation[1];
    *y = (look_info->look_orientation[1] == 0) ?
        look_info->player_info->pos_y + look_info->level *
        look_info->look_orientation[0] :
        look_info->player_info->pos_y + i + look_info->level *
        look_info->look_orientation[0];
}

static int get_len_look_range(core_t *core, look_info_t *look_info)
{
    int x = 0;
    int y = 0;
    int number = 0;
    int len = 0;
    player_info_t *info = look_info->player_info;

    if (look_info->look_orientation[0] == 0)
        number = look_info->look_orientation[1];
    else
        number = look_info->look_orientation[0] * -1;
    for (int i = look_info->level * (number * -1);
        i != (look_info->level + 1) * (number); i += (number)) {
        get_tile_pos(&x, &y, i, look_info);
        check_pos_tile(&core->map, &y, &x);
        len += get_len_object_on_tile(&core->map, x, y);
        if (!(look_info->level == info->level &&
            i * (number) == look_info->level))
            len += strlen(",");
    }
    return (len);
}

static int get_len_look(core_t *core, look_info_t *look_info)
{
    int len = 0;

    for (int level = 0; level != look_info->player_info->level + 1; level++) {
        look_info->level = level;
        len += get_len_look_range(core, look_info);
    }
    len += 5;
    return (len);
}

static void print_object_on_tile(map_t *map, int x, int y,
    look_info_t *look_info)
{
    tile_info_t *info = find_tile(map, x, y);

    for (int i = 0; i != info->nb_food; i++)
        strcat(look_info->str, " food");
    for (int i = 0; i != info->nb_deraumere; i++)
        strcat(look_info->str, " deraumere");
    for (int i = 0; i != info->nb_linemate; i++)
        strcat(look_info->str, " linemate");
    for (int i = 0; i != info->nb_mendiane; i++)
        strcat(look_info->str, " mendiane");
    for (int i = 0; i != info->nb_phiras; i++)
        strcat(look_info->str, " phiras");
    for (int i = 0; i != info->nb_players; i++)
        strcat(look_info->str, " player");
    for (int i = 0; i != info->nb_sibur; i++)
        strcat(look_info->str, " sibur");
    for (int i = 0; i != info->nb_thystame; i++)
        strcat(look_info->str, " thystame");
}

static void print_look_on_tile(core_t *core, look_info_t *look_info)
{
    int x = 0;
    int y = 0;
    int number = 0;
    player_info_t *info = look_info->player_info;

    if (look_info->look_orientation[0] == 0)
        number = look_info->look_orientation[1];
    else
        number = look_info->look_orientation[0] * -1;
    for (int i = look_info->level * (number * -1);
        i != (look_info->level + 1) * (number); i += (number)) {
        get_tile_pos(&x, &y, i, look_info);
        check_pos_tile(&core->map, &y, &x);
        print_object_on_tile(&core->map, x, y, look_info);
        if (!(look_info->level == info->level &&
            i * (number) == look_info->level))
            strcat(look_info->str, ",");
    }
}

void look(core_t *core, int fd, char **command)
{
    look_info_t look_info;
    int len = 0;

    if (command == NULL)
        return;
    look_info.player_info = find_player(&core->players, fd);
    look_info.look_orientation =
        get_look_orientation(look_info.player_info->orientation);
    len = get_len_look(core, &look_info);
    look_info.str = malloc(sizeof(char) * (len + 1));
    look_info.str[0] = '\0';
    strcat(look_info.str, "[");
    for (int level = 0; level != look_info.player_info->level + 1; level++) {
        look_info.level = level;
        print_look_on_tile(core, &look_info);
    }
    strcat(look_info.str, " ]\n");
    send_response(look_info.str, fd);
    free(look_info.look_orientation);
    free(look_info.str);
}
