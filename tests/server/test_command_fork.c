/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_fork
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(command_fork, Command_fork, .init = cr_redirect_stderr)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 2, "team1");
    add_player(&core.map, &core.players, 3, "team1");
    FD_ZERO(&core.select_info.write_fds);
    FD_SET(2, &core.select_info.write_fds);
    FD_SET(3, &core.select_info.write_fds);
    info = find_player(&core.players, 2);
    info->action_queue[0] = strdup("Fork");
    info->timer_action = 0;
    check_player_command(&core);
    info = find_player(&core.players, 2);
    info->action_queue[0] = strdup("Connect_nbr");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_stderr_eq_str("ok\n4\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}
