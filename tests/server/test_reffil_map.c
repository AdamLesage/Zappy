/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_reffil_map
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(reffile_map, simple_reffile_map_valide)
{
    map_t map;
    tile_info_t *info;
    arguments_t arguments;
    bool return_value;
    char *team_names[] = {"team1", "team2", NULL};

    arguments.height = 10;
    arguments.width = 10;
    arguments.nb_client = 2;
    arguments.name_teams = team_names;

    init_map(&map, &arguments);
    reffile_map(&map);
}

Test(reffile_map, multilple_reffile_map)
{
    map_t map;
    tile_info_t *info;
    arguments_t arguments;
    bool return_value;
    char *team_names[] = {"team1", "team2", NULL};

    arguments.height = 10;
    arguments.width = 10;
    arguments.nb_client = 2;
    arguments.name_teams = team_names;

    init_map(&map, &arguments);
    reffile_map(&map);
    reffile_map(&map);
    reffile_map(&map);
}
