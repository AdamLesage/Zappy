/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_inventory
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

void clean_tile(tile_info_t *info)
{
    info->nb_deraumere = 0;
    info->nb_food = 0;
    info->nb_linemate = 0;
    info->nb_mendiane = 0;
    info->nb_phiras = 0;
    info->nb_sibur = 0;
    info->nb_thystame = 0;
    info->nb_players = 0;
}

Test (command_Inventory, command_Inventory_success, .init = cr_redirect_stdout)
{
    core_t core;
    player_info_t *info = NULL;
    tile_info_t *tile_info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    info = find_player(&core.players, 1);
    tile_info = find_tile(&core.map, 5, 5);
    info->orientation = N;
    info->pos_x = 5;
    info->pos_y = 5;
    info->inventory->nb_linemate = 4;
    info->inventory->nb_sibur = 1;
    info->inventory->nb_thystame = 3;
    info->action_queue[0] = strdup("Inventory");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_stdout_eq_str("[ food 10, linemate 4, deraumere 0, sibur 1, mendiane 0, phiras 0, thystame 3 ]\n");
    inventory(&core, 1, NULL);
    delete_player(&core.map, &core.players, 1);
}