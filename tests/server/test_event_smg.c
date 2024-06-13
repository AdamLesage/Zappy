/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_event_smg
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (event_smg, event_smg_success, .init = cr_redirect_stdout)
{
    core_t core;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "GRAPHIC");
    add_player(&core.map, &core.players, 2, "team1");
    add_player(&core.map, &core.players, 3, "team2");
    smg(&core.players, "message 1");
    smg(&core.players, "message to the gui");
    cr_assert_stdout_eq_str("smg message 1\nsmg message to the gui\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
}
