/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** incantation_destroy_stone
*/

#include "server.h"

static void destroy_level_2(tile_info_t *info)
{
    info->nb_linemate--;
}

static void destroy_level_3(tile_info_t *info)
{
    info->nb_linemate--;
    info->nb_deraumere--;
    info->nb_sibur--;
}

static void destroy_level_4(tile_info_t *info)
{
    info->nb_linemate -= 2;
    info->nb_sibur--;
    info->nb_phiras -= 2;
}

static void destroy_level_5(tile_info_t *info)
{
    info->nb_linemate--;
    info->nb_deraumere--;
    info->nb_sibur -= 2;
    info->nb_phiras--;
}

static void destroy_level_6(tile_info_t *info)
{
    info->nb_linemate--;
    info->nb_deraumere -= 2;
    info->nb_sibur--;
    info->nb_mendiane -= 3;
}

static void destroy_level_7(tile_info_t *info)
{
    info->nb_linemate--;
    info->nb_deraumere -= 2;
    info->nb_sibur -= 3;
    info->nb_phiras--;
}

static void destroy_level_8(tile_info_t *info)
{
    info->nb_linemate -= 2;
    info->nb_deraumere -= 2;
    info->nb_sibur -= 2;
    info->nb_mendiane -= 2;
    info->nb_phiras -= 2;
    info->nb_thystame -= 1;
}

void incantation_destroy_stone(tile_info_t *info, int level)
{
    switch (level) {
        case 1:
            return destroy_level_2(info);
        case 2:
            return destroy_level_3(info);
        case 3:
            return destroy_level_4(info);
        case 4:
            return destroy_level_5(info);
        case 5:
            return destroy_level_6(info);
        case 6:
            return destroy_level_7(info);
        case 7:
            return destroy_level_8(info);
        default:
            return;
    }
}
