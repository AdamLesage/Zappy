/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_look
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

void clean_tile(tile_info_t *info)
{
    info->nb_deraumere = 0;
    info->nb_food = 0;
    info->nb_linemate = 0;
    info->nb_mendiane = 0;
    info->nb_phiras = 0;
    info->nb_sibur = 0;
    info->nb_thystame = 0;
    info->nb_players = 0;
}

Test (command_look, command_look_level1)
{
    core_t core;
    player_info_t *info = NULL;
    tile_info_t *tile_info0 = NULL;
    tile_info_t *tile_info1 = NULL;
    tile_info_t *tile_info2 = NULL;
    tile_info_t *tile_info3 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    core.network.client_list = NULL;
    add_player(&core.map, &core.players, 1, "team1");
    add_client_on_network(&core.network, 1);
    info = find_player(&core.players, 1);
    tile_info0 = find_tile(&core.map, 5, 5);
    tile_info1 = find_tile(&core.map, 4, 4);
    tile_info2 = find_tile(&core.map, 5, 4);
    tile_info3 = find_tile(&core.map, 6, 4);
    clean_tile(tile_info0);
    clean_tile(tile_info1);
    clean_tile(tile_info2);
    clean_tile(tile_info3);
    tile_info0->nb_players = 1;
    tile_info0->nb_mendiane = 1;

    tile_info1->nb_phiras = 1;

    tile_info2->nb_sibur = 1;

    tile_info3->nb_thystame = 1;
    info->orientation = N;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Look");
    info->timer_action = 0;
    printf("start\n");
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "[ mendiane player, phiras, sibur, thystame ]\n");
    delete_player(&core.map, &core.players, 1);
    delete_client_of_network(&core.network, 1);
}

Test (command_look, command_look_level3)
{
    core_t core;
    player_info_t *info = NULL;
    tile_info_t *tile_info0 = NULL;

    tile_info_t *tile_info1 = NULL;
    tile_info_t *tile_info2 = NULL;
    tile_info_t *tile_info3 = NULL;

    tile_info_t *tile_info4 = NULL;
    tile_info_t *tile_info5 = NULL;
    tile_info_t *tile_info6 = NULL;
    tile_info_t *tile_info7 = NULL;
    tile_info_t *tile_info8 = NULL;

    tile_info_t *tile_info9 = NULL;
    tile_info_t *tile_info10 = NULL;
    tile_info_t *tile_info11 = NULL;
    tile_info_t *tile_info12 = NULL;
    tile_info_t *tile_info13 = NULL;
    tile_info_t *tile_info14 = NULL;
    tile_info_t *tile_info15 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    core.network.client_list = NULL;
    add_player(&core.map, &core.players, 1, "team1");
    add_client_on_network(&core.network, 1);
    info = find_player(&core.players, 1);
    tile_info0 = find_tile(&core.map, 5, 5);

    tile_info1 = find_tile(&core.map, 4, 4);
    tile_info2 = find_tile(&core.map, 5, 4);
    tile_info3 = find_tile(&core.map, 6, 4);

    tile_info4 = find_tile(&core.map, 3, 3);
    tile_info5 = find_tile(&core.map, 4, 3);
    tile_info6 = find_tile(&core.map, 5, 3);
    tile_info7 = find_tile(&core.map, 6, 3);
    tile_info8 = find_tile(&core.map, 7, 3);

    tile_info9 = find_tile(&core.map, 2, 2);
    tile_info10 = find_tile(&core.map, 3, 2);
    tile_info11 = find_tile(&core.map, 4, 2);
    tile_info12 = find_tile(&core.map, 5, 2);
    tile_info13 = find_tile(&core.map, 6, 2);
    tile_info14 = find_tile(&core.map, 7, 2);
    tile_info15 = find_tile(&core.map, 8, 2);

    clean_tile(tile_info0);
    clean_tile(tile_info1);
    clean_tile(tile_info2);
    clean_tile(tile_info3);
    clean_tile(tile_info4);
    clean_tile(tile_info5);
    clean_tile(tile_info6);
    clean_tile(tile_info7);
    clean_tile(tile_info8);
    clean_tile(tile_info9);
    clean_tile(tile_info10);
    clean_tile(tile_info11);
    clean_tile(tile_info12);
    clean_tile(tile_info13);
    clean_tile(tile_info14);
    clean_tile(tile_info15);

    tile_info0->nb_players = 1;

    tile_info1->nb_phiras = 1;

    tile_info2->nb_sibur = 1;

    tile_info3->nb_thystame = 1;

    tile_info13->nb_linemate = 2;

    tile_info14->nb_food =1;

    tile_info15->nb_deraumere = 3;

    info->level = 3;
    info->orientation = N;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Look");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "[ player, phiras, sibur, thystame,,,,,,,,,, linemate linemate, food, deraumere deraumere deraumere ]\n");
    delete_player(&core.map, &core.players, 1);
    close_server(&core);
}

Test (command_look, command_look_S)
{
    core_t core;
    player_info_t *info = NULL;
    tile_info_t *tile_info0 = NULL;
    tile_info_t *tile_info1 = NULL;
    tile_info_t *tile_info2 = NULL;
    tile_info_t *tile_info3 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    core.network.client_list = NULL;
    add_player(&core.map, &core.players, 1, "team1");
    add_client_on_network(&core.network, 1);
    info = find_player(&core.players, 1);
    tile_info0 = find_tile(&core.map, 5, 5);

    tile_info1 = find_tile(&core.map, 6, 6);
    tile_info2 = find_tile(&core.map, 5, 6);
    tile_info3 = find_tile(&core.map, 4, 6);
    clean_tile(tile_info0);
    clean_tile(tile_info1);
    clean_tile(tile_info2);
    clean_tile(tile_info3);
    tile_info0->nb_players = 1;
    tile_info0->nb_mendiane = 1;

    tile_info1->nb_phiras = 1;

    tile_info2->nb_sibur = 1;

    tile_info3->nb_thystame = 1;
    info->orientation = S;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Look");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "[ mendiane player, phiras, sibur, thystame ]\n");
    delete_player(&core.map, &core.players, 1);
}

Test (command_look, command_look_E)
{
    core_t core;
    player_info_t *info = NULL;
    tile_info_t *tile_info0 = NULL;
    tile_info_t *tile_info1 = NULL;
    tile_info_t *tile_info2 = NULL;
    tile_info_t *tile_info3 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    info = find_player(&core.players, 1);
    tile_info0 = find_tile(&core.map, 5, 5);

    tile_info1 = find_tile(&core.map, 6, 4);
    tile_info2 = find_tile(&core.map, 6, 5);
    tile_info3 = find_tile(&core.map, 6, 6);
    clean_tile(tile_info0);
    clean_tile(tile_info1);
    clean_tile(tile_info2);
    clean_tile(tile_info3);
    tile_info0->nb_players = 1;
    tile_info0->nb_mendiane = 1;

    tile_info1->nb_phiras = 1;

    tile_info2->nb_sibur = 1;

    tile_info3->nb_thystame = 1;
    info->orientation = E;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Look");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "[ mendiane player, phiras, sibur, thystame ]\n");
    delete_player(&core.map, &core.players, 1);
}

Test (command_look, command_look_W)
{
    core_t core;
    player_info_t *info = NULL;
    tile_info_t *tile_info0 = NULL;
    tile_info_t *tile_info1 = NULL;
    tile_info_t *tile_info2 = NULL;
    tile_info_t *tile_info3 = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    info = find_player(&core.players, 1);
    tile_info0 = find_tile(&core.map, 5, 5);

    tile_info1 = find_tile(&core.map, 4, 6);
    tile_info2 = find_tile(&core.map, 4, 5);
    tile_info3 = find_tile(&core.map, 4, 4);
    clean_tile(tile_info0);
    clean_tile(tile_info1);
    clean_tile(tile_info2);
    clean_tile(tile_info3);
    tile_info0->nb_players = 1;
    tile_info0->nb_mendiane = 1;

    tile_info1->nb_phiras = 1;

    tile_info2->nb_sibur = 1;

    tile_info3->nb_thystame = 1;
    info->orientation = W;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Look");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "[ mendiane player, phiras, sibur, thystame ]\n");
    delete_player(&core.map, &core.players, 1);
}