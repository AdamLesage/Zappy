/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_init_map
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (init_map, valid_map_initialization, .init = cr_redirect_stdout)
{
    map_t map;
    arguments_t arguments;
    char *team_names[] = {"team1", "team2", NULL};

    arguments.height = 2;
    arguments.width = 2;
    arguments.nb_client = 2;
    arguments.name_teams = team_names;

    init_map(&map, &arguments);

    cr_assert_eq(map.height, 2);
    cr_assert_eq(map.width, 2);
    cr_assert_eq(map.last_refille, 20);
    tiles_list_t *tmp = map.tiles_list;
    while (tmp != NULL) {
        tiles_list_t *next = tmp->next;
        free(tmp->tile_info);
        free(tmp);
        tmp = next;
    }
}

Test (init_map, large_valid_map_initialization, .init = cr_redirect_stdout)
{
    map_t map;
    arguments_t arguments;
    char *team_names[] = {"team1", "team2", NULL};

    arguments.height = 100;
    arguments.width = 100;
    arguments.nb_client = 10;
    arguments.name_teams = team_names;

    init_map(&map, &arguments);

    cr_assert_eq(map.height, 100);
    cr_assert_eq(map.width, 100);
    cr_assert_eq(map.last_refille, 20);
    tiles_list_t *tmp = map.tiles_list;
    while (tmp != NULL) {
        tiles_list_t *next = tmp->next;
        free(tmp->tile_info);
        free(tmp);
        tmp = next;
    }
}
