/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_interact_player
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (command_interact_player, command_take_success, .init = cr_redirect_stdout)
{
    core_t core;
    player_info_t *info = NULL;
    tile_info_t *tile_info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    info = find_player(&core.players, 1);
    tile_info = find_tile(&core.map, 5, 5);
    tile_info->nb_deraumere = 1;
    tile_info->nb_food = 1;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 1;
    tile_info->nb_phiras = 1;
    tile_info->nb_sibur = 1;
    tile_info->nb_thystame = 1;
    info->pos_x = 5;
    info->pos_y = 5;
    info->action_queue[0] = strdup("Take food");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_food, 0);
    cr_assert_eq(info->inventory->nb_food, 10);

    info->action_queue[0] = strdup("Take deraumere");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_deraumere, 0);
    cr_assert_eq(info->inventory->nb_deraumere, 1);

    info->action_queue[0] = strdup("Take linemate");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_linemate, 0);
    cr_assert_eq(info->inventory->nb_linemate, 1);

    info->action_queue[0] = strdup("Take mendiane");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_mendiane, 0);
    cr_assert_eq(info->inventory->nb_mendiane, 1);

    info->action_queue[0] = strdup("Take phiras");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_phiras, 0);
    cr_assert_eq(info->inventory->nb_phiras, 1);

    info->action_queue[0] = strdup("Take sibur");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_sibur, 0);
    cr_assert_eq(info->inventory->nb_sibur, 1);

    info->action_queue[0] = strdup("Take thystame");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_thystame, 0);
    cr_assert_eq(info->inventory->nb_thystame, 1);

    delete_player(&core.map, &core.players, 1);
}

Test (command_interact_player, command_take_unknow_object, .init = cr_redirect_stdout)
{
    core_t core;
    player_info_t *info = NULL;
    tile_info_t *tile_info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    info = find_player(&core.players, 1);
    tile_info = find_tile(&core.map, 5, 5);
    info->action_queue[0] = strdup("Take test");
    info->timer_action = 0;
    tile_info->nb_deraumere = 1;
    tile_info->nb_food = 1;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 1;
    tile_info->nb_phiras = 1;
    tile_info->nb_sibur = 1;
    tile_info->nb_thystame = 1;
    info->pos_x = 5;
    info->pos_y = 5;
    check_player_command(&core);
    cr_assert_stdout_eq_str("ko\n");

    delete_player(&core.map, &core.players, 1);
}

Test (command_interact_player, command_set_success, .init = cr_redirect_stdout)
{
    core_t core;
    player_info_t *info = NULL;
    tile_info_t *tile_info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    info = find_player(&core.players, 1);
    tile_info = find_tile(&core.map, 5, 5);
    tile_info->nb_deraumere = 1;
    tile_info->nb_food = 1;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 1;
    tile_info->nb_phiras = 1;
    tile_info->nb_sibur = 1;
    tile_info->nb_thystame = 1;
    info->pos_x = 5;
    info->pos_y = 5;
    info->inventory->nb_deraumere = 1;
    info->inventory->nb_linemate = 1;
    info->inventory->nb_mendiane = 1;
    info->inventory->nb_phiras = 1;
    info->inventory->nb_sibur = 1;
    info->inventory->nb_thystame = 1;
    info->action_queue[0] = strdup("Set food");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_food, 2);
    cr_assert_eq(info->inventory->nb_food, 8);

    info->action_queue[0] = strdup("Set deraumere");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_deraumere, 2);
    cr_assert_eq(info->inventory->nb_deraumere, 0);

    info->action_queue[0] = strdup("Set linemate");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_linemate, 2);
    cr_assert_eq(info->inventory->nb_linemate, 0);

    info->action_queue[0] = strdup("Set mendiane");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_mendiane, 2);
    cr_assert_eq(info->inventory->nb_mendiane, 0);

    info->action_queue[0] = strdup("Set phiras");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_phiras, 2);
    cr_assert_eq(info->inventory->nb_phiras, 0);

    info->action_queue[0] = strdup("Set sibur");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_sibur, 2);
    cr_assert_eq(info->inventory->nb_sibur, 0);

    info->action_queue[0] = strdup("Set thystame");
    info->timer_action = 0;
    check_player_command(&core);
    cr_assert_eq(tile_info->nb_thystame, 2);
    cr_assert_eq(info->inventory->nb_thystame, 0);

    delete_player(&core.map, &core.players, 1);
}

Test (command_interact_player, command_set_unknow_object, .init = cr_redirect_stdout)
{
    core_t core;
    player_info_t *info = NULL;
    tile_info_t *tile_info = NULL;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    info = find_player(&core.players, 1);
    tile_info = find_tile(&core.map, 5, 5);
    info->action_queue[0] = strdup("Set test");
    info->timer_action = 0;
    tile_info->nb_deraumere = 1;
    tile_info->nb_food = 1;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 1;
    tile_info->nb_phiras = 1;
    tile_info->nb_sibur = 1;
    tile_info->nb_thystame = 1;
    info->pos_x = 5;
    info->pos_y = 5;
    check_player_command(&core);
    cr_assert_stdout_eq_str("ko\n");

    delete_player(&core.map, &core.players, 1);
}
