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
    FD_ZERO(&core.select_info.write_fds);
    FD_SET(1, &core.select_info.write_fds);
    FD_SET(2, &core.select_info.write_fds);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("message 0, test\n");
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
    FD_ZERO(&core.select_info.write_fds);
    FD_SET(1, &core.select_info.write_fds);
    FD_SET(2, &core.select_info.write_fds);
    info1->pos_x = 5;
    info1->pos_y = 1;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("message 1, test\n");
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
    FD_ZERO(&core.select_info.write_fds);
    FD_SET(1, &core.select_info.write_fds);
    FD_SET(2, &core.select_info.write_fds);
    info1->pos_x = 1;
    info1->pos_y = 1;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("message 2, test\n");
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
    FD_ZERO(&core.select_info.write_fds);
    FD_SET(1, &core.select_info.write_fds);
    FD_SET(2, &core.select_info.write_fds);
    info1->pos_x = 1;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = N;
    info1->action_queue[0] = strdup("Broadcast test");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("message 3, test\n");
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
    FD_ZERO(&core.select_info.write_fds);
    FD_SET(1, &core.select_info.write_fds);
    FD_SET(2, &core.select_info.write_fds);
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
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("message 4, test\n");
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
    FD_ZERO(&core.select_info.write_fds);
    FD_SET(1, &core.select_info.write_fds);
    FD_SET(2, &core.select_info.write_fds);
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
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("message 5, test\n");
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
    FD_ZERO(&core.select_info.write_fds);
    FD_SET(1, &core.select_info.write_fds);
    FD_SET(2, &core.select_info.write_fds);
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
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("message 6, test\n");
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
    FD_ZERO(&core.select_info.write_fds);
    FD_SET(1, &core.select_info.write_fds);
    FD_SET(2, &core.select_info.write_fds);
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
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("message 7, test\n");
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
    FD_ZERO(&core.select_info.write_fds);
    FD_SET(1, &core.select_info.write_fds);
    FD_SET(2, &core.select_info.write_fds);
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
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("message 8, test\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}
