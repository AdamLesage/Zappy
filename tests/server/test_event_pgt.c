/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_event_pgt
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (event_pgt, event_pgt1, .init = cr_redirect_stdout)
{
    core_t core;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "GRAPHIC");
    add_player(&core.map, &core.players, 2, "team1");
    add_player(&core.map, &core.players, 3, "team2");
    pgt(&core.players, 0, Food);
    pgt(&core.players, 0, Linemate);
    pgt(&core.players, 0, Deraumere);
    pgt(&core.players, 0, Sibur);
    pgt(&core.players, 1, Mendiane);
    pgt(&core.players, 0, Phiras);
    pgt(&core.players, 0, Thystame);
    cr_assert_stdout_eq_str("pgt 0 0\npgt 0 1\npgt 0 2\npgt 0 3\npgt 1 4\npgt 0 5\npgt 0 6\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
}
