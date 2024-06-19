/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_check_win_game
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/server/server.h"

Test(win_condition, wind_condition_success, .init = cr_redirect_stderr)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "10", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "GRAPHIC");
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 3, "team1");
    add_player(&core.map, &core.players, 4, "team1");
    add_player(&core.map, &core.players, 5, "team1");
    add_player(&core.map, &core.players, 6, "team1");
    add_player(&core.map, &core.players, 7, "team1");
    info = find_player(&core.players, 1);
    info->level = 8;
    info = find_player(&core.players, 3);
    info->level = 8;
    info = find_player(&core.players, 4);
    info->level = 8;
    info = find_player(&core.players, 5);
    info->level = 8;
    info = find_player(&core.players, 6);
    info->level = 8;
    info = find_player(&core.players, 7);
    info->level = 8;

    check_win_game(&core);
    cr_assert_stderr_eq_str("seg team1\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 3);
}

Test(win_condition, wind_condition_failure, .init = cr_redirect_stderr)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "10", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "GRAPHIC");
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 3, "team1");
    add_player(&core.map, &core.players, 4, "team1");
    add_player(&core.map, &core.players, 5, "team1");
    add_player(&core.map, &core.players, 6, "team1");
    add_player(&core.map, &core.players, 7, "team2");
    info = find_player(&core.players, 1);
    info->level = 8;
    info = find_player(&core.players, 3);
    info->level = 8;
    info = find_player(&core.players, 4);
    info->level = 8;
    info = find_player(&core.players, 5);
    info->level = 8;
    info = find_player(&core.players, 6);
    info->level = 8;
    info = find_player(&core.players, 7);
    info->level = 8;

    check_win_game(&core);
    cr_assert_stderr_neq_str("seg team1\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 3);
}

Test(win_condition, wind_condition_failure2, .init = cr_redirect_stderr)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "10", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "GRAPHIC");
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 3, "team1");
    add_player(&core.map, &core.players, 4, "team1");
    add_player(&core.map, &core.players, 5, "team1");
    add_player(&core.map, &core.players, 6, "team1");
    info = find_player(&core.players, 1);
    info->level = 8;
    info = find_player(&core.players, 3);
    info->level = 8;
    info = find_player(&core.players, 4);
    info->level = 8;
    info = find_player(&core.players, 5);
    info->level = 8;
    info = find_player(&core.players, 6);
    info->level = 8;

    check_win_game(&core);
    cr_assert_stderr_neq_str("seg team1\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 3);
}

Test(win_condition, wind_condition_failure3, .init = cr_redirect_stderr)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "10", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "GRAPHIC");
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 3, "team1");
    add_player(&core.map, &core.players, 4, "team1");
    add_player(&core.map, &core.players, 5, "team1");
    add_player(&core.map, &core.players, 6, "team1");
    add_player(&core.map, &core.players, 7, "team1");
    info = find_player(&core.players, 1);
    info->level = 8;
    info = find_player(&core.players, 3);
    info->level = 8;
    info = find_player(&core.players, 4);
    info->level = 8;
    info = find_player(&core.players, 5);
    info->level = 8;
    info = find_player(&core.players, 6);
    info->level = 7;
    info = find_player(&core.players, 7);
    info->level = 8;

    check_win_game(&core);
    cr_assert_stderr_neq_str("seg team1\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 3);
}