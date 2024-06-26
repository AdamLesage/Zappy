/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_map_put
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

// //// put player ////
Test(put_player, put_on_valide_tile)
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
    info = find_tile(&map, 5, 4);

    cr_assert_eq(info->nb_players, 1);
    cr_assert_eq(return_value, true);
}

Test(put_player, put_on_invalide_tile)
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
    return_value = put_player(&map, -40, 40);
    cr_assert_eq(return_value, false);
}

// //// put linemate ////
Test(put_linemate, put_linemate_on_valide_tile)
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
    return_value = put_linemate(&map, 5, 4);
    info = find_tile(&map, 5, 4);

    cr_assert_eq(info->nb_linemate, 1);
    cr_assert_eq(return_value, true);
}

Test(put_linemate, put_linemate_on_invalide_tile)
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
    return_value = put_linemate(&map, -40, 40);
    cr_assert_eq(return_value, false);
}

// //// put deraumere ////
Test(put_deraumere, put_on_valide_tile)
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
    return_value = put_deraumere(&map, 5, 4);
    info = find_tile(&map, 5, 4);

    cr_assert_eq(info->nb_deraumere, 1);
    cr_assert_eq(return_value, true);
}

Test(put_deraumere, put_on_invalide_tile)
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
    return_value = put_deraumere(&map, -40, 40);
    cr_assert_eq(return_value, false);
}

// //// put sibur ////
Test(put_sibur, put_sibur_on_valide_tile)
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
    return_value = put_sibur(&map, 5, 4);
    info = find_tile(&map, 5, 4);

    cr_assert_eq(info->nb_sibur, 1);
    cr_assert_eq(return_value, true);
}

Test(put_sibur, put_on_invalide_tile)
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
    return_value = put_sibur(&map, -40, 40);
    cr_assert_eq(return_value, false);
}

// //// put mendiane ////
Test(put_mendiane, put_on_valide_tile)
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
    return_value = put_mendiane(&map, 5, 4);
    cr_assert_eq(return_value, true);
}

Test(put_mendiane, put_on_invalide_tile)
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
    return_value = put_mendiane(&map, -40, 40);
    cr_assert_eq(return_value, false);
}

// //// put phiras ////
Test(put_phiras, put_on_valide_tile)
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
    return_value = put_phiras(&map, 5, 4);
    info = find_tile(&map, 5, 4);

    cr_assert_eq(info->nb_phiras, 1);
    cr_assert_eq(return_value, true);
}

Test(put_phiras, put_on_invalide_tile)
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
    return_value = put_phiras(&map, -40, 40);
    cr_assert_eq(return_value, false);
}

// //// put thystame ////
Test(put_thystame, put_on_valide_tile)
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
    return_value = put_thystame(&map, 5, 4);
    info = find_tile(&map, 5, 4);

    cr_assert_eq(info->nb_thystame, 1);
    cr_assert_eq(return_value, true);
}

Test(put_thystame, put_on_invalide_tile)
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
    return_value = put_thystame(&map, -40, 40);
    cr_assert_eq(return_value, false);
}

// //// put eggs ////
Test(put_eggs, put_on_valide_tile)
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
    return_value = put_eggs(&map, 5, 4, "name1");

    cr_assert_str_eq(map.eggs->team_name, "name1");
    cr_assert_eq(find_number_eggs_on_team(map.eggs, "name1"), 1);
    cr_assert_eq(return_value, true);
}

Test(put_eggs, put_on_same_team_eggs)
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
    return_value = put_eggs(&map, 5, 4, "name1");
    return_value = put_eggs(&map, 5, 4, "name1");
    return_value = put_eggs(&map, 5, 4, "name1");

    cr_assert_str_eq(map.eggs->team_name, "name1");
    cr_assert_eq(map.eggs->pos_x, 5);
    cr_assert_eq(map.eggs->pos_y, 4);
    cr_assert_eq(find_number_eggs_on_team(map.eggs, "name1"), 3);
    cr_assert_eq(return_value, true);
}

Test(put_eggs, put_on_different_team_eggs)
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
    return_value = put_eggs(&map, 5, 4, "team1");
    return_value = put_eggs(&map, 5, 4, "team2");
    return_value = put_eggs(&map, 5, 4, "team1");

    cr_assert_eq(find_number_eggs_on_team(map.eggs, "team1"), 4);
    cr_assert_eq(find_number_eggs_on_team(map.eggs, "team2"), 3);
    cr_assert_eq(return_value, true);
}

Test(put_eggs, put_on_invalide_tile)
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
    return_value = put_eggs(&map, -20, 40, "name1");
    cr_assert_eq(return_value, false);
}

//// put food ////
Test(put_food, put_on_valide_tile)
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
    return_value = put_food(&map, 5, 4);
    info = find_tile(&map, 5, 4);

    cr_assert_eq(info->nb_food, 1);
    cr_assert_eq(return_value, true);
}

Test(put_food, put_on_invalide_tile)
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
    return_value = put_food(&map, -40, 40);
    cr_assert_eq(return_value, false);
}
