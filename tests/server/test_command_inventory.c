/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_inventory
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (command_Inventory, command_Inventory_success)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    info = find_player(&core.players, 1);
    info->orientation = N;
    info->pos_x = 5;
    info->pos_y = 5;
    info->inventory->nb_linemate = 4;
    info->inventory->nb_sibur = 1;
    info->inventory->nb_thystame = 3;
    info->action_queue[0] = strdup("Inventory");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "[ food 9, linemate 4, deraumere 0, sibur 1, mendiane 0, phiras 0, thystame 3 ]\n");
    inventory(&core, 1, NULL);
    delete_player(&core.map, &core.players, 1);
}
