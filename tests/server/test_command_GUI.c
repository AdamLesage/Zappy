/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_GUI
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(msz, test_msz)
{
    core_t core;
    char *command[] = {"msz", NULL};
    char *expected = "msz 10 10\n";

    core.map.width = 10;
    core.map.height = 10;
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    msz(&core, 1, command);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, expected);
}

Test(tna, test_tna)
{
    core_t core;
    char *command[] = {"tna", NULL};
    char *team_names[] = {"team1", "team2", NULL};
    char *expected = "tna team1\ntna team2\n";

    core.arguments.name_teams = team_names;
    core.arguments.nb_teams = 2;
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    tna(&core, 1, command);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, expected);
}

Test(sgt, test_sgt, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"sgt", NULL};
    char *expected = "sgt 100\n";

    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    core.arguments.frequency = 100;
    sgt(&core, 1, command);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, expected);
}

Test(sst, test_sst, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"sst", "100", NULL};
    char *expected = "sst 100\n";

    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    core.arguments.frequency = 100;
    sst(&core, 1, command);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, expected);
}

Test(bct, test_bct, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"bct", "5", "4", NULL};
    char *expected = "bct 5 4 0 0 0 0 0 0 0\n";

    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    core.map.width = 10;
    core.map.height = 10;
    tiles_list_t tile;
    tile.pos_x = 5;
    tile.pos_y = 4;
    tile_info_t tile_info = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    tile.tile_info = &tile_info;
    tile.next = NULL;
    core.map.tiles_list = &tile;
    bct(&core, 1, command);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, expected);
}

Test(mct, test_mct, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"mct", NULL};
    char *expected = "bct 0 0 0 0 0 0 0 0 0\nbct 0 1 0 0 0 0 0 0 0\n";

    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    core.map.width = 10;
    core.map.height = 10;
    tiles_list_t tile;
    tile.pos_x = 0;
    tile.pos_y = 0;
    tile_info_t tile_info = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    tile.tile_info = &tile_info;
    tile.next = NULL;
    core.map.tiles_list = &tile;

    tiles_list_t tile2;
    tile2.pos_x = 0;
    tile2.pos_y = 1;
    tile_info_t tile_info2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    tile2.tile_info = &tile_info2;
    tile2.next = NULL;
    tile.next = &tile2;
    mct(&core, 1, command);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, expected);
}

Test(pin, test_pin, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"pin", "1", NULL};
    char *expected = "pin 1 0 0 0 0 0 0 0 0 0\n";

    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    core.map.width = 10;
    core.map.height = 10;
    players_list_t player;
    player.fd = 1;
    inventory_t inventory = {0, 0, 0, 0, 0, 0, 0};
    player_info_t player_info = {0, 0, 1, &inventory, {NULL}, NULL, 0, N, 1, "team1", 0, NULL, 1};

    player.player_info = &player_info;
    player.next = NULL;
    core.players.players_list = &player;
    
    pin(&core, 1, command);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, expected);
}

Test(ppo, test_ppo, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"ppo", "1", NULL};
    char *expected = "ppo 1 0 0 1\n";

    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    core.map.width = 10;
    core.map.height = 10;
    players_list_t player;
    player.fd = 1;
    inventory_t inventory = {0, 0, 0, 0, 0, 0, 0};
    player_info_t player_info = {0, 0, 1, &inventory, {NULL}, NULL, 0, N, 1, "team1", 0, NULL, 1};

    player.player_info = &player_info;
    player.next = NULL;
    core.players.players_list = &player;
    
    ppo(&core, 1, command);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, expected);
}

Test(plv, test_plv, .init = cr_redirect_stdout)
{
    core_t core;
    char *command[] = {"plv", "1", NULL};
    char *expected = "plv 1 1\n";

    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    core.map.width = 10;
    core.map.height = 10;
    players_list_t player;
    player.fd = 1;
    inventory_t inventory = {0, 0, 0, 0, 0, 0, 0};
    player_info_t player_info = {0, 0, 1, &inventory, {NULL}, NULL, 0, N, 1, "team1", 0, NULL, 1};

    player.player_info = &player_info;
    player.next = NULL;
    core.players.players_list = &player;
    
    plv(&core, 1, command);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, expected);
}
