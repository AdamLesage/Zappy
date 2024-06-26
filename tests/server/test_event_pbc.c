/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_event_pbc
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (event_pbc, event_pbc1)
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
    pbc(&core, info->id, "test_message");
    pbc(&core, info2->id, "\"other message\"");
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "pbc 0 test_message\npbc 1 \"other message\"\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
}
