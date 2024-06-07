/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_GUI
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(msz, test_msz, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"msz", NULL};
    char *team_names[] = {"team1", "team2", NULL};
    char *expected = "msz 10 10\n";

    core.map.width = 10;
    core.map.height = 10;
    msz(&core, 1, command);
    cr_assert_stdout_eq_str(expected);
}

Test(tna, test_tna, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"tna", NULL};
    char *team_names[] = {"team1", "team2", NULL};
    char *expected = "tna team1\ntna team2\n";

    core.arguments.name_teams = team_names;
    core.arguments.nb_teams = 2;
    tna(&core, 1, command);
    cr_assert_stdout_eq_str(expected);
}

Test(sgt, test_sgt, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"sgt", NULL};
    char *team_names[] = {"team1", "team2", NULL};
    char *expected = "sgt 100\n";

    core.arguments.frequency = 100;
    sgt(&core, 1, command);
    cr_assert_stdout_eq_str(expected);
}

Test(sst, test_sst, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"sst", "100", NULL};
    char *team_names[] = {"team1", "team2", NULL};
    char *expected = "sst 100\n";

    core.arguments.frequency = 100;
    sst(&core, 1, command);
    cr_assert_stdout_eq_str(expected);
}

Test(bct, test_bct, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"bct", "5", "4", NULL};
    char *expected = "bct 5 4 0 0 0 0 0 0 0\n";

    core.map.width = 10;
    core.map.height = 10;
    tiles_list_t tile;
    tile.pos_x = 5;
    tile.pos_y = 4;
    tile_info_t tile_info = {0, 0, 0, 0, 0, 0, 0};
    tile.tile_info = &tile_info;
    tile.next = NULL;
    core.map.tiles_list = &tile;
    bct(&core, 1, command);
    cr_assert_stdout_eq_str(expected);
}

Test(mct, test_mct, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"mct", NULL};
    char *expected = "bct 0 0 0 0 0 0 0 0 0\nbct 0 1 0 0 0 0 0 0 0\n";

    core.map.width = 10;
    core.map.height = 10;
    tiles_list_t tile;
    tile.pos_x = 0;
    tile.pos_y = 0;
    tile_info_t tile_info = {0, 0, 0, 0, 0, 0, 0};
    tile.tile_info = &tile_info;
    tile.next = NULL;
    core.map.tiles_list = &tile;

    tiles_list_t tile2;
    tile2.pos_x = 0;
    tile2.pos_y = 1;
    tile_info_t tile_info2 = {0, 0, 0, 0, 0, 0, 0};
    tile2.tile_info = &tile_info2;
    tile2.next = NULL;
    tile.next = &tile2;
    mct(&core, 1, command);
    cr_assert_stdout_eq_str(expected);
}
