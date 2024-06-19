/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_eject
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

void redirect_all_stdout2(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(command_Eject, Command_Eject_N, .init = redirect_all_stdout2)
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
    info1->orientation = N;
    info1->pos_x = 5;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = S;
    info1->action_queue[0] = strdup("Eject");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(info2->pos_y, 4);
    cr_assert_eq(info2->pos_x, 5);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("eject: 1\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Eject, Command_Eject_N_cross, .init = redirect_all_stdout2)
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
    info1->orientation = N;
    info1->pos_x = 5;
    info1->pos_y = 0;
    info2->pos_x = 5;
    info2->pos_y = 0;
    info2->orientation = S;
    info1->action_queue[0] = strdup("Eject");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(info2->pos_y, 9);
    cr_assert_eq(info2->pos_x, 5);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("eject: 1\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Eject, Command_Eject_S, .init = redirect_all_stdout2)
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
    info1->orientation = S;
    info1->pos_x = 5;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = S;
    info1->action_queue[0] = strdup("Eject");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(info2->pos_y, 6);
    cr_assert_eq(info2->pos_x, 5);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("eject: 5\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Eject, Command_Eject_S_cross, .init = redirect_all_stdout2)
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
    info1->orientation = S;
    info1->pos_x = 5;
    info1->pos_y = 9;
    info2->pos_x = 5;
    info2->pos_y = 9;
    info2->orientation = S;
    info1->action_queue[0] = strdup("Eject");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(info2->pos_y, 0);
    cr_assert_eq(info2->pos_x, 5);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("eject: 5\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Eject, Command_Eject_E, .init = redirect_all_stdout2)
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
    FD_ZERO(&core.select_info.write_fds);
    FD_SET(1, &core.select_info.write_fds);
    FD_SET(2, &core.select_info.write_fds);
    info2 = find_player(&core.players, 2);
    info1->orientation = E;
    info1->pos_x = 5;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = S;
    info1->action_queue[0] = strdup("Eject");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(info2->pos_y, 5);
    cr_assert_eq(info2->pos_x, 6);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("eject: 7\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Eject, Command_Eject_E_cross, .init = redirect_all_stdout2)
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
    info1->orientation = E;
    info1->pos_x = 9;
    info1->pos_y = 5;
    info2->pos_x = 9;
    info2->pos_y = 5;
    info2->orientation = S;
    info1->action_queue[0] = strdup("Eject");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(info2->pos_y, 5);
    cr_assert_eq(info2->pos_x, 0);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("eject: 7\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Eject, Command_Eject_W, .init = redirect_all_stdout2)
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
    info1->orientation = W;
    info1->pos_x = 5;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->orientation = S;
    info1->action_queue[0] = strdup("Eject");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(info2->pos_y, 5);
    cr_assert_eq(info2->pos_x, 4);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("eject: 3\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Eject, Command_Eject_W_cross, .init = redirect_all_stdout2)
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
    info1->orientation = W;
    info1->pos_x = 0;
    info1->pos_y = 5;
    info2->pos_x = 0;
    info2->pos_y = 5;
    info2->orientation = S;
    info1->action_queue[0] = strdup("Eject");
    info1->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(info2->pos_y, 5);
    cr_assert_eq(info2->pos_x, 9);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_stderr_eq_str("eject: 3\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}