/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_event_pdr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (event_pdr, event_pdr1)
{
    core_t core;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "GRAPHIC");
    add_player(&core.map, &core.players, 2, "team1");
    add_player(&core.map, &core.players, 3, "team2");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    pdr(&core, 0, Food);
    pdr(&core, 0, Linemate);
    pdr(&core, 0, Deraumere);
    pdr(&core, 0, Sibur);
    pdr(&core, 1, Mendiane);
    pdr(&core, 0, Phiras);
    pdr(&core, 0, Thystame);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "pdr 0 0\npdr 0 1\npdr 0 2\npdr 0 3\npdr 1 4\npdr 0 5\npdr 0 6\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
}