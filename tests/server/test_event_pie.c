/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_event_pie
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (event_pie, event_pie_success, .init = cr_redirect_stdout)
{
    core_t core;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "GRAPHIC");
    add_player(&core.map, &core.players, 2, "team1");
    add_player(&core.map, &core.players, 3, "team2");
    pie(&core.players, 3, 5, true);
    pie(&core.players, 9, 0, false);
    cr_assert_stdout_eq_str("pie 3 5 1\npie 9 0 0\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
}
