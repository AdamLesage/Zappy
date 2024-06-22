/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_event_pnw
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (event_pnw, event_pnw_success)
{
    core_t core;
    player_info_t *info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "GRAPHIC");
    add_player(&core.map, &core.players, 2, "team1");
    info = find_player(&core.players, 2);
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info->orientation = N;
    info->pos_x = 5;
    info->pos_y = 5;
    info->inventory->nb_linemate = 4;
    info->inventory->nb_sibur = 1;
    info->inventory->nb_thystame = 3;
    pnw(&core, info);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "pnw 0 5 5 1 1 team1\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
}

Test (event_pnw, event_pnw_success2, .init = cr_redirect_stdout)
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
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info = find_player(&core.players, 2);
    info2 = find_player(&core.players, 3);
    info->orientation = N;
    info->pos_x = 2;
    info->pos_y = 8;
    info->inventory->nb_linemate = 4;
    info->inventory->nb_sibur = 1;
    info->inventory->nb_thystame = 3;
    info2->orientation = S;
    info2->pos_x = 9;
    info2->pos_y = 8;
    info2->inventory->nb_linemate = 4;
    info2->inventory->nb_sibur = 1;
    info2->inventory->nb_thystame = 3;
    info2->level = 4;
    pnw(&core, info);
    pnw(&core, info2);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "pnw 0 2 8 1 1 team1\npnw 1 9 8 3 4 team2\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
}
