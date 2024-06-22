/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_move_player
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (command_move_player, command_forward_N)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_player(&core.map, &core.players, 2, "team1");
    info = find_player(&core.players, 2);
    info->orientation = N;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Forward");
    info->timer_action = 1;
    check_player_command(&core);
    cr_assert_eq(info->timer_action, 0);
    check_player_command(&core);
    cr_assert_eq(info->pos_x, 5);
    cr_assert_eq(info->pos_y, 4);
    cr_assert_eq(info->orientation, N);
    delete_player(&core.map, &core.players, 2);
}

Test (command_move_player, command_forward_N_cross_map)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    info = find_player(&core.players, 2);
    info->orientation = N;
    info->pos_x = 5;
    info->pos_y = 0;
    info->action_queue[0] = strdup("Forward");
    info->timer_action = 1;
    check_player_command(&core);
    cr_assert_eq(info->timer_action, 0);
    check_player_command(&core);
    cr_assert_eq(info->pos_x, 5);
    cr_assert_eq(info->pos_y, 9);
    cr_assert_eq(info->orientation, N);
    delete_player(&core.map, &core.players, 2);
}

Test (command_move_player, command_forward_S)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    info = find_player(&core.players, 2);
    info->orientation = S;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Forward");
    info->timer_action = 1;
    check_player_command(&core);
    cr_assert_eq(info->timer_action, 0);
    check_player_command(&core);
    cr_assert_eq(info->pos_x, 5);
    cr_assert_eq(info->pos_y, 6);
    cr_assert_eq(info->orientation, S);
    delete_player(&core.map, &core.players, 2);
}

Test (command_move_player, command_forward_S_cross_map)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    info = find_player(&core.players, 2);
    info->orientation = S;
    info->pos_x = 5;
    info->pos_y = 9;
    info->action_queue[0] = strdup("Forward");
    info->timer_action = 1;
    check_player_command(&core);
    cr_assert_eq(info->timer_action, 0);
    check_player_command(&core);
    cr_assert_eq(info->pos_x, 5);
    cr_assert_eq(info->pos_y, 0);
    cr_assert_eq(info->orientation, S);
    delete_player(&core.map, &core.players, 2);
}

Test (command_move_player, command_forward_E)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    info = find_player(&core.players, 2);
    info->orientation = E;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Forward");
    info->timer_action = 1;
    check_player_command(&core);
    cr_assert_eq(info->timer_action, 0);
    check_player_command(&core);
    cr_assert_eq(info->pos_x, 6);
    cr_assert_eq(info->pos_y, 5);
    cr_assert_eq(info->orientation, E);
    delete_player(&core.map, &core.players, 2);
}

Test (command_move_player, command_forward_E_cross_map)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    info = find_player(&core.players, 2);
    info->orientation = E;
    info->pos_x = 9;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Forward");
    info->timer_action = 1;
    check_player_command(&core);
    cr_assert_eq(info->timer_action, 0);
    check_player_command(&core);
    cr_assert_eq(info->pos_x, 0);
    cr_assert_eq(info->pos_y, 5);
    cr_assert_eq(info->orientation, E);
    delete_player(&core.map, &core.players, 2);
}

Test (command_move_player, command_forward_W)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    info = find_player(&core.players, 2);
    info->orientation = W;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Forward");
    info->timer_action = 1;
    check_player_command(&core);
    cr_assert_eq(info->timer_action, 0);
    check_player_command(&core);
    cr_assert_eq(info->pos_x, 4);
    cr_assert_eq(info->pos_y, 5);
    cr_assert_eq(info->orientation, W);
    delete_player(&core.map, &core.players, 2);
}

Test (command_move_player, command_forward_W_cross_map)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    info = find_player(&core.players, 2);
    info->orientation = W;
    info->pos_x = 0;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Forward");
    info->timer_action = 1;
    check_player_command(&core);
    cr_assert_eq(info->timer_action, 0);
    check_player_command(&core);
    cr_assert_eq(info->pos_x, 9);
    cr_assert_eq(info->pos_y, 5);
    cr_assert_eq(info->orientation, W);
    delete_player(&core.map, &core.players, 2);
}

Test (command_move_player, command_Right)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    info = find_player(&core.players, 2);
    info->orientation = W;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Right");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(info->pos_x, 5);
    cr_assert_eq(info->pos_y, 5);
    cr_assert_eq(info->orientation, N);
    delete_player(&core.map, &core.players, 2);
}

Test (command_move_player, command_Left)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    info = find_player(&core.players, 2);
    info->orientation = S;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Left");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(info->pos_x, 5);
    cr_assert_eq(info->pos_y, 5);
    cr_assert_eq(info->orientation, E);
    delete_player(&core.map, &core.players, 2);
}
