/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_player_function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (player_function, add_delete_find)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    player_info_t *player_info;
    bool return_value = false;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    return_value = add_player(&map, &players, 2, "team1");
    cr_assert_eq(return_value, true);
    return_value = add_player(&map, &players, 3, "team2");
    cr_assert_eq(return_value, true);
    player_info = find_player(&players, 3);
    cr_assert_eq(player_info->fd, 3);
    cr_assert_str_eq(player_info->team_name, "team2");
    return_value = delete_player(&map, &players, 3);
    cr_assert_eq(return_value, true);
    player_info = find_player(&players, 2);
    cr_assert_eq(player_info->fd, 2);
    cr_assert_str_eq(player_info->team_name, "team1");
    return_value = delete_player(&map, &players, 2);
    cr_assert_eq(return_value, true);
}

Test (player_function, add_player_error_unknow_team)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    bool return_value = false;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    return_value = add_player(&map, &players, 2, "abc");
    cr_assert_eq(return_value, false);
}

Test (player_function, add_player_capcity_exeded)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    bool return_value = false;

    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    return_value = add_player(&map, &players, 2, "team1");
    cr_assert_eq(return_value, true);
    return_value = add_player(&map, &players, 3, "team1");
    cr_assert_eq(return_value, true);
    return_value = add_player(&map, &players, 4, "team1");
    cr_assert_eq(return_value, true);
    return_value = add_player(&map, &players, 5, "team1");
    cr_assert_eq(return_value, true);
    return_value = add_player(&map, &players, 6, "team1");
    cr_assert_eq(return_value, true);
    return_value = add_player(&map, &players, 7, "team2");
    cr_assert_eq(return_value, true);
    return_value = add_player(&map, &players, 8, "team1");
    cr_assert_eq(return_value, false);
    return_value = delete_player(&map, &players, 2);
    cr_assert_eq(return_value, true);
    return_value = delete_player(&map, &players, 3);
    cr_assert_eq(return_value, true);
    return_value = delete_player(&map, &players, 4);
    cr_assert_eq(return_value, true);
    return_value = delete_player(&map, &players, 5);
    cr_assert_eq(return_value, true);
    return_value = delete_player(&map, &players, 6);
    cr_assert_eq(return_value, true);
    return_value = delete_player(&map, &players, 7);
    cr_assert_eq(return_value, true);
}

Test (player_function, delete_player_unknow_player)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    bool return_value = false;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    return_value = add_player(&map, &players, 2, "team1");
    cr_assert_eq(return_value, true);
    return_value = add_player(&map, &players, 3, "team1");
    cr_assert_eq(return_value, true);
    return_value = delete_player(&map, &players, 10);
    cr_assert_eq(return_value, false);
    return_value = delete_player(&map, &players, 2);
    return_value = delete_player(&map, &players, 3);
}

Test (player_function, find_player_unknow_player)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    player_info_t *player_info;
    bool return_value = false;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    return_value = add_player(&map, &players, 2, "team1");
    cr_assert_eq(return_value, true);
    return_value = add_player(&map, &players, 3, "team1");
    cr_assert_eq(return_value, true);
    player_info = find_player(&players, 4);
    cr_assert_eq(player_info, NULL);
    return_value = delete_player(&map, &players, 2);
    return_value = delete_player(&map, &players, 3);
}

Test (player_function, player_move_N)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    player_info_t *player_info;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");
    player_info = find_player(&players, 2);
    player_info->orientation = N;
    int prev_x = player_info->pos_x;
    int prev_y = player_info->pos_y;
    move_player(&map, &players, 2);
    player_info = find_player(&players, 2);
    if (prev_y == 0) {
        cr_assert_eq(player_info->pos_y, map.height - 1);
        cr_assert_eq(player_info->pos_x, prev_x);
    } else {
        cr_assert_eq(player_info->pos_y, prev_y - 1);
        cr_assert_eq(player_info->pos_x, prev_x);
    }

    delete_player(&map, &players, 2);
}

Test (player_function, player_move_S)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    player_info_t *player_info;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");
    player_info = find_player(&players, 2);
    player_info->orientation = S;
    int prev_x = player_info->pos_x;
    int prev_y = player_info->pos_y;
    move_player(&map, &players, 2);
    player_info = find_player(&players, 2);
    if (prev_y == map.height - 1) {
        cr_assert_eq(player_info->pos_y, 0);
        cr_assert_eq(player_info->pos_x, prev_x);
    } else {
        cr_assert_eq(player_info->pos_y, prev_y + 1);
        cr_assert_eq(player_info->pos_x, prev_x);
    }

    delete_player(&map, &players, 2);
}

Test (player_function, player_move_E)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    player_info_t *player_info;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");
    player_info = find_player(&players, 2);
    player_info->orientation = E;
    int prev_x = player_info->pos_x;
    int prev_y = player_info->pos_y;
    move_player(&map, &players, 2);
    player_info = find_player(&players, 2);
    if (prev_x == map.width - 1) {
        cr_assert_eq(player_info->pos_x, 0);
        cr_assert_eq(player_info->pos_y, prev_y);
    } else {
        cr_assert_eq(player_info->pos_x, prev_x - 1);
        cr_assert_eq(player_info->pos_y, prev_y);
    }

    delete_player(&map, &players, 2);
}

Test (player_function, player_move_W)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    player_info_t *player_info;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");
    player_info = find_player(&players, 2);
    player_info->orientation = W;
    int prev_x = player_info->pos_x;
    int prev_y = player_info->pos_y;
    move_player(&map, &players, 2);
    player_info = find_player(&players, 2);
    if (prev_x == 0) {
        cr_assert_eq(player_info->pos_x, map.width - 1);
        cr_assert_eq(player_info->pos_y, prev_y);
    } else {
        cr_assert_eq(player_info->pos_x, prev_x - 1);
        cr_assert_eq(player_info->pos_y, prev_y);
    }

    delete_player(&map, &players, 2);
}

Test (player_function, player_turn_left)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");

    players.players_list->player_info->orientation = N;
    turn_left(&players, 2);
    cr_assert_eq(players.players_list->player_info->orientation, W);
    turn_left(&players, 2);
    cr_assert_eq(players.players_list->player_info->orientation, S);
    turn_left(&players, 2);
    cr_assert_eq(players.players_list->player_info->orientation, E);
    turn_left(&players, 2);
    cr_assert_eq(players.players_list->player_info->orientation, N);
    delete_player(&map, &players, 2);
}

Test (player_function, player_turn_right)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");

    players.players_list->player_info->orientation = N;
    turn_right(&players, 2);
    cr_assert_eq(players.players_list->player_info->orientation, E);
    turn_right(&players, 2);
    cr_assert_eq(players.players_list->player_info->orientation, S);
    turn_right(&players, 2);
    cr_assert_eq(players.players_list->player_info->orientation, W);
    turn_right(&players, 2);
    cr_assert_eq(players.players_list->player_info->orientation, N);
    delete_player(&map, &players, 2);
}

Test (player_function, player_get_inventory)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    inventory_t *inventory;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");

    players.players_list->player_info->inventory->nb_deraumere = 4;
    players.players_list->player_info->inventory->nb_food = 5;
    players.players_list->player_info->inventory->nb_linemate = 1;
    players.players_list->player_info->inventory->nb_mendiane = 3;
    players.players_list->player_info->inventory->nb_phiras = 9;
    players.players_list->player_info->inventory->nb_sibur = 7;
    players.players_list->player_info->inventory->nb_thystame = 2;
    inventory = get_inventory(&players, 2);
    cr_assert_eq(inventory->nb_deraumere, 4);
    cr_assert_eq(inventory->nb_food, 5);
    cr_assert_eq(inventory->nb_linemate, 1);
    cr_assert_eq(inventory->nb_mendiane, 3);
    cr_assert_eq(inventory->nb_phiras, 9);
    cr_assert_eq(inventory->nb_sibur, 7);
    cr_assert_eq(inventory->nb_thystame, 2);
    inventory = get_inventory(&players, 1);
    cr_assert_eq(inventory, NULL);
    delete_player(&map, &players, 2);
}

Test (player_function, player_get_pos)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    int *pos;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");

    players.players_list->player_info->pos_x = 2;
    players.players_list->player_info->pos_y = 4;
    pos = get_pos(&players, 2);
    cr_assert_eq(pos[0], 2);
    cr_assert_eq(pos[1], 4);
    pos = get_pos(&players, 1);
    cr_assert_eq(pos, NULL);
    delete_player(&map, &players, 2);
}

Test (player_function, player_get_level)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    int level;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");

    players.players_list->player_info->level = 5;
    level = get_level(&players, 2);
    cr_assert_eq(level, 5);
    level = get_level(&players, 1);
    cr_assert_eq(level, -1);
    delete_player(&map, &players, 2);
}

Test (player_function, player_get_player_team)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    char *team_name;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");

    team_name = get_player_team(&players, 2);
    cr_assert_str_eq(team_name, "team1");
    team_name = get_player_team(&players, 1);
    cr_assert_eq(team_name, NULL);
    delete_player(&map, &players, 2);
}

Test (player_function, player_find_nb_player_on_team)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    int number;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");
    add_player(&map, &players, 3, "team1");
    add_player(&map, &players, 4, "team1");
    add_player(&map, &players, 5, "team1");
    add_player(&map, &players, 6, "team2");
    add_player(&map, &players, 7, "team2");
    add_player(&map, &players, 8, "team2");

    number = find_nb_player_on_team(&players, "team1");
    cr_assert_eq(number, 4);
    number = find_nb_player_on_team(&players, "team2");
    cr_assert_eq(number, 3);
    number = find_nb_player_on_team(&players, "team35");
    cr_assert_eq(number, 0);
    delete_player(&map, &players, 2);
}

// // Test (player_function, player_put_on_inventory)
// // {
// //     players_t players;
// //     arguments_t arguments;
// //     map_t map;
// //     int number;
// //     player_info_t *player_info;
// //     const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
// //     int argc = 12;

// //     get_arguments(&arguments, argc, argv);
// //     init_players(&players, &arguments);
// //     init_map(&map, &arguments);
// //     add_player(&map, &players, 2, "team1", &arguments);

// //     put_on_inventory();
// //     delete_player(&map, &players, 2);
// // }

Test (player_function, player_queue)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    char *action;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");

    add_action_in_queue(&players, 2, "test");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test");
    cr_assert_eq(players.players_list->player_info->action_queue[1], NULL);
    add_action_in_queue(&players, 2, "other");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test");
    cr_assert_str_eq(players.players_list->player_info->action_queue[1], "other");
    action = get_action_in_queue(&players, 2);
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "other");
    cr_assert_eq(players.players_list->player_info->action_queue[1], NULL);
    cr_assert_str_eq(action, "test");
    action = get_action_in_queue(&players, 2);
    cr_assert_eq(players.players_list->player_info->action_queue[0], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[1], NULL);
    cr_assert_str_eq(action, "other");
    action = get_action_in_queue(&players, 2);
    cr_assert_eq(players.players_list->player_info->action_queue[0], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[1], NULL);
    cr_assert_eq(action, NULL);
    delete_player(&map, &players, 2);
}

Test (player_function, player_queue_full)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");

    add_action_in_queue(&players, 2, "test1");
    add_action_in_queue(&players, 2, "test2");
    add_action_in_queue(&players, 2, "test3");
    add_action_in_queue(&players, 2, "test4");
    add_action_in_queue(&players, 2, "test5");
    add_action_in_queue(&players, 2, "test6");
    add_action_in_queue(&players, 2, "test7");
    add_action_in_queue(&players, 2, "test8");
    add_action_in_queue(&players, 2, "test9");
    add_action_in_queue(&players, 2, "test10");
    add_action_in_queue(&players, 2, "test11");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test1");
    cr_assert_str_eq(players.players_list->player_info->action_queue[1], "test2");
    cr_assert_str_eq(players.players_list->player_info->action_queue[2], "test3");
    cr_assert_str_eq(players.players_list->player_info->action_queue[3], "test4");
    cr_assert_str_eq(players.players_list->player_info->action_queue[4], "test5");
    cr_assert_str_eq(players.players_list->player_info->action_queue[5], "test6");
    cr_assert_str_eq(players.players_list->player_info->action_queue[6], "test7");
    cr_assert_str_eq(players.players_list->player_info->action_queue[7], "test8");
    cr_assert_str_eq(players.players_list->player_info->action_queue[8], "test9");
    cr_assert_str_eq(players.players_list->player_info->action_queue[9], "test10");
    cr_assert_str_eq(get_action_in_queue(&players, 2), "test1");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test2");
    cr_assert_str_eq(players.players_list->player_info->action_queue[1], "test3");
    cr_assert_str_eq(players.players_list->player_info->action_queue[2], "test4");
    cr_assert_str_eq(players.players_list->player_info->action_queue[3], "test5");
    cr_assert_str_eq(players.players_list->player_info->action_queue[4], "test6");
    cr_assert_str_eq(players.players_list->player_info->action_queue[5], "test7");
    cr_assert_str_eq(players.players_list->player_info->action_queue[6], "test8");
    cr_assert_str_eq(players.players_list->player_info->action_queue[7], "test9");
    cr_assert_str_eq(players.players_list->player_info->action_queue[8], "test10");
    cr_assert_eq(players.players_list->player_info->action_queue[9], NULL);
    cr_assert_str_eq(get_action_in_queue(&players, 2), "test2");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test3");
    cr_assert_str_eq(players.players_list->player_info->action_queue[1], "test4");
    cr_assert_str_eq(players.players_list->player_info->action_queue[2], "test5");
    cr_assert_str_eq(players.players_list->player_info->action_queue[3], "test6");
    cr_assert_str_eq(players.players_list->player_info->action_queue[4], "test7");
    cr_assert_str_eq(players.players_list->player_info->action_queue[5], "test8");
    cr_assert_str_eq(players.players_list->player_info->action_queue[6], "test9");
    cr_assert_str_eq(players.players_list->player_info->action_queue[7], "test10");
    cr_assert_eq(players.players_list->player_info->action_queue[8], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[9], NULL);
    cr_assert_str_eq(get_action_in_queue(&players, 2), "test3");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test4");
    cr_assert_str_eq(players.players_list->player_info->action_queue[1], "test5");
    cr_assert_str_eq(players.players_list->player_info->action_queue[2], "test6");
    cr_assert_str_eq(players.players_list->player_info->action_queue[3], "test7");
    cr_assert_str_eq(players.players_list->player_info->action_queue[4], "test8");
    cr_assert_str_eq(players.players_list->player_info->action_queue[5], "test9");
    cr_assert_str_eq(players.players_list->player_info->action_queue[6], "test10");
    cr_assert_eq(players.players_list->player_info->action_queue[7], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[8], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[9], NULL);
    cr_assert_str_eq(get_action_in_queue(&players, 2), "test4");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test5");
    cr_assert_str_eq(players.players_list->player_info->action_queue[1], "test6");
    cr_assert_str_eq(players.players_list->player_info->action_queue[2], "test7");
    cr_assert_str_eq(players.players_list->player_info->action_queue[3], "test8");
    cr_assert_str_eq(players.players_list->player_info->action_queue[4], "test9");
    cr_assert_str_eq(players.players_list->player_info->action_queue[5], "test10");
    cr_assert_eq(players.players_list->player_info->action_queue[6], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[7], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[8], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[9], NULL);
    cr_assert_str_eq(get_action_in_queue(&players, 2), "test5");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test6");
    cr_assert_str_eq(players.players_list->player_info->action_queue[1], "test7");
    cr_assert_str_eq(players.players_list->player_info->action_queue[2], "test8");
    cr_assert_str_eq(players.players_list->player_info->action_queue[3], "test9");
    cr_assert_str_eq(players.players_list->player_info->action_queue[4], "test10");
    cr_assert_eq(players.players_list->player_info->action_queue[5], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[6], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[7], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[8], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[9], NULL);
    cr_assert_str_eq(get_action_in_queue(&players, 2), "test6");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test7");
    cr_assert_str_eq(players.players_list->player_info->action_queue[1], "test8");
    cr_assert_str_eq(players.players_list->player_info->action_queue[2], "test9");
    cr_assert_str_eq(players.players_list->player_info->action_queue[3], "test10");
    cr_assert_eq(players.players_list->player_info->action_queue[4], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[5], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[6], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[7], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[8], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[9], NULL);
    cr_assert_str_eq(get_action_in_queue(&players, 2), "test7");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test8");
    cr_assert_str_eq(players.players_list->player_info->action_queue[1], "test9");
    cr_assert_str_eq(players.players_list->player_info->action_queue[2], "test10");
    cr_assert_eq(players.players_list->player_info->action_queue[3], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[4], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[5], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[6], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[7], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[8], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[9], NULL);
    cr_assert_str_eq(get_action_in_queue(&players, 2), "test8");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test9");
    cr_assert_str_eq(players.players_list->player_info->action_queue[1], "test10");
    cr_assert_eq(players.players_list->player_info->action_queue[2], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[3], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[4], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[5], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[6], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[7], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[8], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[9], NULL);
    cr_assert_str_eq(get_action_in_queue(&players, 2), "test9");
    cr_assert_str_eq(players.players_list->player_info->action_queue[0], "test10");
    cr_assert_eq(players.players_list->player_info->action_queue[1], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[2], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[3], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[4], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[5], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[6], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[7], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[8], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[9], NULL);
    cr_assert_str_eq(get_action_in_queue(&players, 2), "test10");
    cr_assert_eq(players.players_list->player_info->action_queue[0], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[1], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[2], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[3], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[4], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[5], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[6], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[7], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[8], NULL);
    cr_assert_eq(players.players_list->player_info->action_queue[9], NULL);
    
    delete_player(&map, &players, 2);
}



Test (player_function, player_queue_unknow)
{
    players_t players;
    arguments_t arguments;
    map_t map;
    char *action;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    init_players(&players, &arguments);
    init_map(&map, &arguments);
    add_player(&map, &players, 2, "team1");

    add_action_in_queue(&players, 1, "test");
    action = get_action_in_queue(&players, 1);
    cr_assert_eq(action, NULL);
    delete_player(&map, &players, 2);
}