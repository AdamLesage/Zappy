/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_init_players
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test (init_players, valid_players_initialization)
{
    players_t players;
    arguments_t arguments;

    arguments.nb_teams = 10;
    arguments.nb_client = 5;
    init_players(&players, &arguments);
    cr_assert_eq(players.nb_teams, 10);
    cr_assert_eq(players.nb_client, 5);
    cr_assert_eq(players.players_list, NULL);
}

Test (init_players, valid_players_initialization2)
{
    players_t players;
    arguments_t arguments;

    arguments.nb_teams = 109;
    arguments.nb_client = 52;
    init_players(&players, &arguments);
    cr_assert_eq(players.nb_teams, 109);
    cr_assert_eq(players.nb_client, 52);
    cr_assert_eq(players.players_list, NULL);
}
