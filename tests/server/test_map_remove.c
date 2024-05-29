/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_map_remove
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

// bool remove_player(Map_t *map, int x, int y);
// bool remove_linemate(Map_t *map, int x, int y);
// bool remove_deraumere(Map_t *map, int x, int y);
// bool remove_sibur(Map_t *map, int x, int y);
// bool remove_mendiane(Map_t *map, int x, int y);
// bool remove_phiras(Map_t *map, int x, int y);
// bool remove_thystame(Map_t *map, int x, int y);
// bool remove_eggs(Map_t *map, int x, int y);

Test(remove_of_map, remove_on_valide_tile)
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
    return_value = put_player(&map, 5, 4);
    return_value = put_player(&map, 5, 4);
    return_value = remove_player(&map, 5, 4);
    cr_assert_eq(return_value, true);

    return_value = put_linemate(&map, 5, 4);
    return_value = put_linemate(&map, 5, 4);
    return_value = remove_linemate(&map, 5, 4);
    cr_assert_eq(return_value, true);

    return_value = put_deraumere(&map, 5, 4);
    return_value = put_deraumere(&map, 5, 4);
    return_value = remove_deraumere(&map, 5, 4);
    cr_assert_eq(return_value, true);

    return_value = put_sibur(&map, 5, 4);
    return_value = put_sibur(&map, 5, 4);
    return_value = remove_sibur(&map, 5, 4);

    return_value = put_mendiane(&map, 5, 4);
    return_value = put_mendiane(&map, 5, 4);
    return_value = remove_mendiane(&map, 5, 4);
    cr_assert_eq(return_value, true);

    return_value = put_phiras(&map, 5, 4);
    return_value = put_phiras(&map, 5, 4);
    return_value = remove_phiras(&map, 5, 4);
    cr_assert_eq(return_value, true);

    return_value = put_thystame(&map, 5, 4);
    return_value = put_thystame(&map, 5, 4);
    return_value = remove_thystame(&map, 5, 4);
    cr_assert_eq(return_value, true);

    return_value = put_eggs(&map, 5, 4);
    return_value = put_eggs(&map, 5, 4);
    return_value = remove_eggs(&map, 5, 4);
    cr_assert_eq(return_value, true);

    info = find_tile_info(&map, 5, 4);
    cr_assert_eq(info->nb_players, 1);
    cr_assert_eq(info->nb_linemate, 1);
    cr_assert_eq(info->nb_deraumere, 1);
    cr_assert_eq(info->nb_sibur, 1);
    cr_assert_eq(info->nb_mendiane, 1);
    cr_assert_eq(info->nb_phiras, 1);
    cr_assert_eq(info->nb_thystame, 1);
}

Test(remove_of_map, remove_on_invalide_tile)
{
    map_t map;
    arguments_t arguments;
    bool return_value;
    char *team_names[] = {"team1", "team2", NULL};

    arguments.height = 10;
    arguments.width = 10;
    arguments.nb_client = 2;
    arguments.name_teams = team_names;

    init_map(&map, &arguments);
    return_value = put_player(&map, 20, 4);
    return_value = put_player(&map, 20, 4);
    return_value = remove_player(&map, 20, 4);
    cr_assert_eq(return_value, false);

    return_value = put_linemate(&map, 20, 4);
    return_value = put_linemate(&map, 20, 4);
    return_value = remove_linemate(&map, 20, 4);
    cr_assert_eq(return_value, false);

    return_value = put_deraumere(&map, 20, 4);
    return_value = put_deraumere(&map, 20, 4);
    return_value = remove_deraumere(&map, 20, 4);
    cr_assert_eq(return_value, false);

    return_value = put_sibur(&map, 20, 4);
    return_value = put_sibur(&map, 20, 4);
    return_value = remove_sibur(&map, 20, 4);

    return_value = put_mendiane(&map, 20, 4);
    return_value = put_mendiane(&map, 20, 4);
    return_value = remove_mendiane(&map, 20, 4);
    cr_assert_eq(return_value, false);

    return_value = put_phiras(&map, 20, 4);
    return_value = put_phiras(&map, 20, 4);
    return_value = remove_phiras(&map, 20, 4);
    cr_assert_eq(return_value, false);

    return_value = put_thystame(&map, 20, 4);
    return_value = put_thystame(&map, 20, 4);
    return_value = remove_thystame(&map, 20, 4);
    cr_assert_eq(return_value, false);

    return_value = put_eggs(&map, 20, 4);
    return_value = put_eggs(&map, 20, 4);
    return_value = remove_eggs(&map, 20, 4);
    cr_assert_eq(return_value, false);
}

Test(remove_of_map, remove_on_wrong_tile)
{
    map_t map;
    arguments_t arguments;
    bool return_value;
    char *team_names[] = {"team1", "team2", NULL};

    arguments.height = 10;
    arguments.width = 10;
    arguments.nb_client = 2;
    arguments.name_teams = team_names;

    init_map(&map, &arguments);
    return_value = remove_player(&map, 5, 4);
    cr_assert_eq(return_value, false);
    return_value = remove_linemate(&map, 5, 4);
    cr_assert_eq(return_value, false);
    return_value = remove_deraumere(&map, 5, 4);
    cr_assert_eq(return_value, false);
    return_value = remove_sibur(&map, 5, 4);
    return_value = remove_mendiane(&map, 5, 4);
    cr_assert_eq(return_value, false);
    return_value = remove_phiras(&map, 5, 4);
    cr_assert_eq(return_value, false);
    return_value = remove_thystame(&map, 5, 4);
    cr_assert_eq(return_value, false);
    return_value = remove_eggs(&map, 5, 4);
    cr_assert_eq(return_value, false);
}
