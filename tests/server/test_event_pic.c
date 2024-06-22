/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_event_pic
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (event_pic, event_pic1)
{
    core_t core;
    incantation_info_t *incantation = malloc(sizeof(incantation_info_t));

    incantation->pos_y = 2;
    incantation->pos_x = 2;
    incantation->nb_players = 2;
    incantation->ids = malloc(sizeof(int) * 3) ;
    incantation->ids[0] = 0;
    incantation->ids[1] = 1;
    incantation->ids[2] = -1;
    incantation->incantation_level = 4;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "GRAPHIC");
    add_player(&core.map, &core.players, 2, "team1");
    add_player(&core.map, &core.players, 3, "team2");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);

    pic(&core, incantation);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "pic 2 2 4 0 1\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
    free(incantation->ids);
}

