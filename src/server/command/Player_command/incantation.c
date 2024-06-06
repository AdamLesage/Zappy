/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** incantation
*/

#include "server.h"

static int nb_player_at_level(players_list_t *player_list, int level,
    int x, int y)
{
    int nb = 0;

    for (players_list_t *tmp = player_list; tmp != NULL; tmp = tmp->next) {
        if (tmp->player_info->level == level) {
            nb++;
        }
    }
    return nb;
}

static bool valide_level_2(tile_info_t *tile_info,
    players_list_t *players_list)
{
    if (nb_player_at_level(players_list, 1, tile_info->pos_x,
        tile_info->pos_y) >= 1 && tile_info->nb_linemate >= 1) {
        return (true);
    }
    return (false);
}

static bool valide_level_3(tile_info_t *tile_info,
    players_list_t *players_list)
{
    if (nb_player_at_level(players_list, 2, tile_info->pos_x,
        tile_info->pos_y) >= 2 && tile_info->nb_linemate >= 1 &&
        tile_info->nb_deraumere >= 1 && tile_info->nb_sibur >= 1) {
        return (true);
    }
    return (false);
}

static bool valide_level_4(tile_info_t *tile_info,
    players_list_t *players_list)
{
    int is_valide = 0;

    if (nb_player_at_level(players_list, 3, tile_info->pos_x,
        tile_info->pos_y) >= 2) {
        is_valide++;
    }
    if (tile_info->nb_linemate >= 2) {
        is_valide++;
    }
    if (tile_info->nb_sibur >= 1) {
        is_valide++;
    }
    if (tile_info->nb_phiras >= 2) {
        is_valide++;
    }
    if (is_valide == 4) {
        return (true);
    }
    return (false);
}

static bool valide_level_5(tile_info_t *tile_info,
    players_list_t *players_list)
{
    int is_valide = 0;

    if (nb_player_at_level(players_list, 4, tile_info->pos_x,
        tile_info->pos_y) >= 4)
        is_valide++;
    if (tile_info->nb_linemate >= 1)
        is_valide++;
    if (tile_info->nb_deraumere >= 1)
        is_valide++;
    if (tile_info->nb_sibur >= 2)
        is_valide++;
    if (tile_info->nb_phiras >= 1)
        is_valide++;
    if (is_valide == 5)
        return (true);
    return (false);
}

static bool valide_level_6(tile_info_t *tile_info,
    players_list_t *players_list)
{
    int is_valide = 0;

    if (nb_player_at_level(players_list, 5, tile_info->pos_x,
        tile_info->pos_y) >= 4)
        is_valide++;
    if (tile_info->nb_linemate >= 1)
        is_valide++;
    if (tile_info->nb_deraumere >= 2)
        is_valide++;
    if (tile_info->nb_sibur >= 1)
        is_valide++;
    if (tile_info->nb_mendiane >= 3)
        is_valide++;
    if (is_valide == 5) {
        return (true);
    }
    return (false);
}

static bool valide_level_7(tile_info_t *tile_info,
    players_list_t *players_list)
{
    int is_valide = 0;

    if (nb_player_at_level(players_list, 6, tile_info->pos_x,
        tile_info->pos_y) >= 6)
        is_valide++;
    if (tile_info->nb_linemate >= 1)
        is_valide++;
    if (tile_info->nb_deraumere >= 2)
        is_valide++;
    if (tile_info->nb_sibur >= 3)
        is_valide++;
    if (tile_info->nb_phiras >= 1)
        is_valide++;
    if (is_valide == 5) {
        return (true);
    }
    return (false);
}

static bool valide_level_8(tile_info_t *tile_info,
    players_list_t *players_list)
{
    int is_valide = 0;

    if (nb_player_at_level(players_list, 7, tile_info->pos_x,
        tile_info->pos_y) >= 6)
        is_valide++;
    if (tile_info->nb_linemate >= 2)
        is_valide++;
    if (tile_info->nb_deraumere >= 2)
        is_valide++;
    if (tile_info->nb_sibur >= 2)
        is_valide++;
    if (tile_info->nb_mendiane >= 2)
        is_valide++;
    if (tile_info->nb_phiras >= 2)
        is_valide++;
    if (tile_info->nb_thystame >= 1)
        is_valide++;
    if (is_valide == 7)
        return (true);
    return (false);
}

void incantation(core_t *core, int fd, char **command)
{
    printf("invantation\n");
}
