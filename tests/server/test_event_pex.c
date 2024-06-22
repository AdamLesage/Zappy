/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_event_pex
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (event_pex, event_pex1)
{
    core_t core;
    player_info_t *info = NULL;
    player_info_t *info2 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "GRAPHIC");
    add_player(&core.map, &core.players, 2, "team1");
    add_player(&core.map, &core.players, 3, "team2");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    info = find_player(&core.players, 2);
    info2 = find_player(&core.players, 3);
    pex(&core, info);
    pex(&core, info2);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "pex 0\npex 1\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
}
