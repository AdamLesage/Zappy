/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_broadcast
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

void redirect_all_stdout3(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(command_Broadcast, Command_Broadcast_same_case, .init = redirect_all_stdout3)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "message 0, test\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Broadcast, Command_Broadcast_N, .init = redirect_all_stdout3)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1->pos_x = 5;
    info1->pos_y = 1;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "message 1, test\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Broadcast, Command_Broadcast_N_W, .init = redirect_all_stdout3)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1->pos_x = 1;
    info1->pos_y = 1;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "message 2, test\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Broadcast, Command_Broadcast_W, .init = redirect_all_stdout3)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1->pos_x = 1;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "message 3, test\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Broadcast, Command_Broadcast_S_W, .init = redirect_all_stdout3)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    info1->pos_x = 1;
    info1->pos_y = 8;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "message 4, test\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Broadcast, Command_Broadcast_S, .init = redirect_all_stdout3)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    info1->pos_x = 5;
    info1->pos_y = 8;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "message 5, test\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Broadcast, Command_Broadcast_S_E, .init = redirect_all_stdout3)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    info1->pos_x = 8;
    info1->pos_y = 8;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "message 6, test\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Broadcast, Command_Broadcast_E, .init = redirect_all_stdout3)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    info1->pos_x = 8;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "message 7, test\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Broadcast, Command_Broadcast_N_E, .init = redirect_all_stdout3)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    info1->pos_x = 8;
    info1->pos_y = 2;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "message 8, test\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}
