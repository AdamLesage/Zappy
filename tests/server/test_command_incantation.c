/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_incantation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

void redirect_all_stdout4(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(command_Incantation, Command_Incantation_sucess_level_1, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    tile_info->nb_deraumere = 0;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 0;
    tile_info->nb_sibur = 0;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_eq(info1->is_on_incantation, true);
    cr_assert_eq(info2->is_on_incantation, true);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_level, 1);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 300);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_x, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_y, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->nb_players, 2);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[1], 0);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[0], 1);
    check_player_command(&core);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 299);
    check_player_command(&core);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 298);

    core.players.incantation_list->incantation_info->incantation_timer = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nElevation underway\nCurrent level: 2\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "Elevation underway\nCurrent level: 2\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Incantation, Command_Incantation_multiple_level_1, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    tile_info_t *tile_info = NULL;
    tile_info_t *tile_info2 = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info2->pos_x = 8;
    info2->pos_y = 2;
    tile_info = find_tile(&core.map, 5, 5);
    tile_info2 = find_tile(&core.map, 8, 2);
    tile_info->nb_deraumere = 0;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 0;
    tile_info->nb_sibur = 0;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;

    tile_info2->nb_food = 0;
    tile_info2->nb_linemate = 1;
    tile_info2->nb_mendiane = 0;
    tile_info2->nb_phiras = 0;
    tile_info2->nb_sibur = 0;
    tile_info2->nb_thystame = 0;
    tile_info2->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info2->action_queue[0] = strdup("Left");
    info2->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    info2->last_action = 0;
    check_player_command(&core);
    cr_assert_eq(info1->is_on_incantation, true);
    cr_assert_eq(info2->is_on_incantation, true);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_level, 1);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 300);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_x, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_y, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->nb_players, 1);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[0], 0);

    cr_assert_eq(core.players.incantation_list->next->incantation_info->incantation_level, 1);
    cr_assert_eq(core.players.incantation_list->next->incantation_info->incantation_timer, 300);
    cr_assert_eq(core.players.incantation_list->next->incantation_info->pos_x, 8);
    cr_assert_eq(core.players.incantation_list->next->incantation_info->pos_y, 2);
    cr_assert_eq(core.players.incantation_list->next->incantation_info->nb_players, 1);
    cr_assert_eq(core.players.incantation_list->next->incantation_info->ids[0], 1);
    check_player_command(&core);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 299);
    cr_assert_eq(core.players.incantation_list->next->incantation_info->incantation_timer, 299);
    check_player_command(&core);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 298);
    cr_assert_eq(core.players.incantation_list->next->incantation_info->incantation_timer, 298);

    core.players.incantation_list->next->incantation_info->incantation_timer = 0;
    core.players.incantation_list->incantation_info->incantation_timer = 1;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "ok\nElevation underway\nCurrent level: 2\n");
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nElevation underway\nCurrent level: 2\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
}

Test(command_Incantation, Command_Incantation_failure_start_level_1, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    tile_info->nb_deraumere = 0;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 0;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 0;
    tile_info->nb_sibur = 0;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nko\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Incantation, Command_Incantation_failure_end_level_1, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    tile_info->nb_deraumere = 0;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 0;
    tile_info->nb_sibur = 0;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_eq(info1->is_on_incantation, true);
    cr_assert_eq(info2->is_on_incantation, true);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_level, 1);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 300);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_x, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_y, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->nb_players, 2);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[1], 0);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[0], 1);
    check_player_command(&core);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 299);
    check_player_command(&core);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 298);

    tile_info->nb_linemate = 0;
    core.players.incantation_list->incantation_info->incantation_timer = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nElevation underway\nko\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "Elevation underway\nko\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Incantation, Command_Incantation_sucess_level_2, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 2;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->level = 2;
    tile_info->nb_deraumere = 1;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 0;
    tile_info->nb_sibur = 1;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_eq(info1->is_on_incantation, true);
    cr_assert_eq(info2->is_on_incantation, true);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_level, 2);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 300);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_x, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_y, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->nb_players, 2);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[1], 0);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[0], 1);
    check_player_command(&core);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 299);
    check_player_command(&core);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 298);

    core.players.incantation_list->incantation_info->incantation_timer = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nElevation underway\nCurrent level: 3\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "Elevation underway\nCurrent level: 3\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Incantation, Command_Incantation_failure_level_2, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 2;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->level = 2;
    tile_info->nb_deraumere = 1;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 0;
    tile_info->nb_sibur = 0;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_eq(info1->is_on_incantation, false);
    cr_assert_eq(info2->is_on_incantation, false);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nko\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
}

Test(command_Incantation, Command_Incantation_level_2_not_same_pos, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 2;
    info2->pos_x = 2;
    info2->pos_y = 5;
    info2->level = 2;
    tile_info->nb_deraumere = 1;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 0;
    tile_info->nb_sibur = 1;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nko\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Incantation, Command_Incantation_level_2_not_same_level, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 2;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->level = 4;
    tile_info->nb_deraumere = 1;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 0;
    tile_info->nb_sibur = 1;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nko\n");
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Incantation, Command_Incantation_level_2_death_of_a_player, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 2;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->level = 2;
    tile_info->nb_deraumere = 1;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 0;
    tile_info->nb_sibur = 1;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);

    core.players.incantation_list->incantation_info->incantation_timer = 0;
    delete_player(&core.map, &core.players, 2);
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nElevation underway\nko\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "Elevation underway\n");
    delete_player(&core.map, &core.players, 1);
}

Test(command_Incantation, Command_Incantation_sucess_level_3, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 3;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->level = 3;
    tile_info->nb_deraumere = 0;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 2;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 2;
    tile_info->nb_sibur = 1;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_eq(info1->is_on_incantation, true);
    cr_assert_eq(info2->is_on_incantation, true);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_level, 3);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 300);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_x, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_y, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->nb_players, 2);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[1], 0);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[0], 1);
    check_player_command(&core);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 299);
    check_player_command(&core);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 298);

    core.players.incantation_list->incantation_info->incantation_timer = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nElevation underway\nCurrent level: 4\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "Elevation underway\nCurrent level: 4\n");
    cr_assert_eq(tile_info->nb_deraumere, 0);
    cr_assert_eq(tile_info->nb_linemate, 0);
    cr_assert_eq(tile_info->nb_mendiane, 0);
    cr_assert_eq(tile_info->nb_phiras, 0);
    cr_assert_eq(tile_info->nb_sibur, 0);
    cr_assert_eq(tile_info->nb_thystame, 0);
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Incantation, Command_Incantation_failure_level_3, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 3;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->level = 3;
    tile_info->nb_deraumere = 0;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 2;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 1;
    tile_info->nb_sibur = 0;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nko\n");
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
}

Test(command_Incantation, Command_Incantation_sucess_level_4, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    player_info_t *info3 = NULL;
    player_info_t *info4 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    add_player(&core.map, &core.players, 3, "team1");
    add_player(&core.map, &core.players, 4, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    info3 = find_player(&core.players, 3);
    info4 = find_player(&core.players, 4);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 4;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->level = 4;
    info3->pos_x = 5;
    info3->pos_y = 5;
    info3->level = 4;
    info4->pos_x = 5;
    info4->pos_y = 5;
    info4->level = 4;
    tile_info->nb_deraumere = 1;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 1;
    tile_info->nb_sibur = 2;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_eq(info1->is_on_incantation, true);
    cr_assert_eq(info2->is_on_incantation, true);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_level, 4);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 300);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_x, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_y, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->nb_players, 4);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[0], 3);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[1], 2);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[2], 1);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[3], 0);

    core.players.incantation_list->incantation_info->incantation_timer = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nElevation underway\nCurrent level: 5\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "Elevation underway\nCurrent level: 5\n");
    cr_assert_eq(tile_info->nb_deraumere, 0);
    cr_assert_eq(tile_info->nb_linemate, 0);
    cr_assert_eq(tile_info->nb_mendiane, 0);
    cr_assert_eq(tile_info->nb_phiras, 0);
    cr_assert_eq(tile_info->nb_sibur, 0);
    cr_assert_eq(tile_info->nb_thystame, 0);
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
}

Test(command_Incantation, Command_Incantation_failure_level_4, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 4;
    tile_info->nb_deraumere = 1;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 1;
    tile_info->nb_sibur = 1;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 2;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nko\n");
    delete_player(&core.map, &core.players, 1);
}

Test(command_Incantation, Command_Incantation_sucess_level_5, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    player_info_t *info3 = NULL;
    player_info_t *info4 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    add_player(&core.map, &core.players, 3, "team1");
    add_player(&core.map, &core.players, 4, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    info3 = find_player(&core.players, 3);
    info4 = find_player(&core.players, 4);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 5;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->level = 5;
    info3->pos_x = 5;
    info3->pos_y = 5;
    info3->level = 5;
    info4->pos_x = 5;
    info4->pos_y = 5;
    info4->level = 5;
    tile_info->nb_deraumere = 2;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 3;
    tile_info->nb_phiras = 0;
    tile_info->nb_sibur = 1;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 4;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_eq(info1->is_on_incantation, true);
    cr_assert_eq(info2->is_on_incantation, true);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_level, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 300);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_x, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_y, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->nb_players, 4);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[0], 3);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[1], 2);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[2], 1);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[3], 0);

    core.players.incantation_list->incantation_info->incantation_timer = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nElevation underway\nCurrent level: 6\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "Elevation underway\nCurrent level: 6\n");
    cr_assert_eq(tile_info->nb_deraumere, 0);
    cr_assert_eq(tile_info->nb_linemate, 0);
    cr_assert_eq(tile_info->nb_mendiane, 0);
    cr_assert_eq(tile_info->nb_phiras, 0);
    cr_assert_eq(tile_info->nb_sibur, 0);
    cr_assert_eq(tile_info->nb_thystame, 0);
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
    delete_player(&core.map, &core.players, 4);
}

Test(command_Incantation, Command_Incantation_sucess_level_6, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    player_info_t *info3 = NULL;
    player_info_t *info4 = NULL;
    player_info_t *info5 = NULL;
    player_info_t *info6 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "10", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    add_player(&core.map, &core.players, 3, "team1");
    add_player(&core.map, &core.players, 4, "team1");
    add_player(&core.map, &core.players, 5, "team1");
    add_player(&core.map, &core.players, 6, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    info3 = find_player(&core.players, 3);
    info4 = find_player(&core.players, 4);
    info5 = find_player(&core.players, 5);
    info6 = find_player(&core.players, 6);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 6;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->level = 6;
    info3->pos_x = 5;
    info3->pos_y = 5;
    info3->level = 6;
    info4->pos_x = 5;
    info4->pos_y = 5;
    info4->level = 6;
    info5->pos_x = 5;
    info5->pos_y = 5;
    info5->level = 6;
    info6->pos_x = 5;
    info6->pos_y = 5;
    info6->level = 6;
    tile_info->nb_deraumere = 2;
    tile_info->nb_food = 0;
    tile_info->nb_linemate = 1;
    tile_info->nb_mendiane = 0;
    tile_info->nb_phiras = 1;
    tile_info->nb_sibur = 3;
    tile_info->nb_thystame = 0;
    tile_info->nb_players = 6;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_eq(info1->is_on_incantation, true);
    cr_assert_eq(info2->is_on_incantation, true);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_level, 6);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 300);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_x, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_y, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->nb_players, 6);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[0], 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[1], 4);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[2], 3);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[3], 2);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[4], 1);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[5], 0);

    core.players.incantation_list->incantation_info->incantation_timer = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nElevation underway\nCurrent level: 7\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "Elevation underway\nCurrent level: 7\n");
    cr_assert_eq(tile_info->nb_deraumere, 0);
    cr_assert_eq(tile_info->nb_linemate, 0);
    cr_assert_eq(tile_info->nb_mendiane, 0);
    cr_assert_eq(tile_info->nb_phiras, 0);
    cr_assert_eq(tile_info->nb_sibur, 0);
    cr_assert_eq(tile_info->nb_thystame, 0);
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
    delete_player(&core.map, &core.players, 4);
}

Test(command_Incantation, Command_Incantation_sucess_level_7, .init = redirect_all_stdout4)
{
    core_t core;
    player_info_t *info1 = NULL;
    player_info_t *info2 = NULL;
    player_info_t *info3 = NULL;
    player_info_t *info4 = NULL;
    player_info_t *info5 = NULL;
    player_info_t *info6 = NULL;
    tile_info_t *tile_info = NULL;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "team2", "-c", "10", "-f", "100", NULL};
    int argc = 12;

    init_core(argc, argv, &core);
    add_player(&core.map, &core.players, 1, "team1");
    add_player(&core.map, &core.players, 2, "team1");
    add_player(&core.map, &core.players, 3, "team1");
    add_player(&core.map, &core.players, 4, "team1");
    add_player(&core.map, &core.players, 5, "team1");
    add_player(&core.map, &core.players, 6, "team1");
    core.network.client_list = NULL;
    add_client_on_network(&core.network, 2);
    add_client_on_network(&core.network, 1);
    info1 = find_player(&core.players, 1);
    info2 = find_player(&core.players, 2);
    info3 = find_player(&core.players, 3);
    info4 = find_player(&core.players, 4);
    info5 = find_player(&core.players, 5);
    info6 = find_player(&core.players, 6);
    tile_info = find_tile(&core.map, 5, 5);
    info1->pos_x = 5;
    info1->pos_y = 5;
    info1->level = 7;
    info2->pos_x = 5;
    info2->pos_y = 5;
    info2->level = 7;
    info3->pos_x = 5;
    info3->pos_y = 5;
    info3->level = 7;
    info4->pos_x = 5;
    info4->pos_y = 5;
    info4->level = 7;
    info5->pos_x = 5;
    info5->pos_y = 5;
    info5->level = 7;
    info6->pos_x = 5;
    info6->pos_y = 5;
    info6->level = 7;
    tile_info->nb_deraumere = 2;
    tile_info->nb_linemate = 2;
    tile_info->nb_mendiane = 2;
    tile_info->nb_phiras = 2;
    tile_info->nb_sibur = 2;
    tile_info->nb_thystame = 1;
    tile_info->nb_players = 6;
    info1->action_queue[0] = strdup("Right");
    info1->action_queue[1] = strdup("Incantation");
    info1->last_action = 0;
    check_player_command(&core);
    cr_assert_eq(info1->is_on_incantation, true);
    cr_assert_eq(info2->is_on_incantation, true);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_level, 7);
    cr_assert_eq(core.players.incantation_list->incantation_info->incantation_timer, 300);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_x, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->pos_y, 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->nb_players, 6);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[0], 5);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[1], 4);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[2], 3);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[3], 2);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[4], 1);
    cr_assert_eq(core.players.incantation_list->incantation_info->ids[5], 0);

    core.players.incantation_list->incantation_info->incantation_timer = 0;
    check_player_command(&core);
    cr_assert_str_eq(core.network.client_list->client_info->buffer_send, "ok\nElevation underway\nCurrent level: 8\n");
    cr_assert_str_eq(core.network.client_list->next->client_info->buffer_send, "Elevation underway\nCurrent level: 8\n");
    cr_assert_eq(tile_info->nb_deraumere, 0);
    cr_assert_eq(tile_info->nb_linemate, 0);
    cr_assert_eq(tile_info->nb_mendiane, 0);
    cr_assert_eq(tile_info->nb_phiras, 0);
    cr_assert_eq(tile_info->nb_sibur, 0);
    cr_assert_eq(tile_info->nb_thystame, 0);
    delete_player(&core.map, &core.players, 1);
    delete_player(&core.map, &core.players, 2);
    delete_player(&core.map, &core.players, 3);
    delete_player(&core.map, &core.players, 4);
}