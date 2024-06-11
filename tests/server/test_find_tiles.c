/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_find_tiles
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

//// put player ////
Test(find_tile, find_on_unset_map)
{
    map_t map;
    tile_info_t *info;
    arguments_t arguments;
    char *team_names[] = {"team1", "team2", NULL};

    arguments.height = 10;
    arguments.width = 10;
    arguments.nb_client = 2;
    arguments.name_teams = team_names;

    init_map(&map, &arguments);
    info = find_tile(NULL, 5, 4);
    cr_assert_eq(info, NULL);
}

Test(find_tile, find_invalide_tile)
{
    map_t map;
    tile_info_t *info;
    arguments_t arguments;
    char *team_names[] = {"team1", "team2", NULL};

    arguments.height = 10;
    arguments.width = 10;
    arguments.nb_client = 2;
    arguments.name_teams = team_names;

    init_map(&map, &arguments);
    info = find_tile(&map, -10, 20);
    cr_assert_eq(info, NULL);
}
