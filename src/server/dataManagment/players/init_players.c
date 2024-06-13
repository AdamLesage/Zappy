/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** init_players
*/

#include "server_data.h"
#include <unistd.h>

void init_players(players_t *players, arguments_t *arguments)
{
    players->nb_client = arguments->nb_client;
    players->nb_teams = arguments->nb_teams;
    players->players_list = NULL;
    players->current_id = 0;
    players->incantation_list = NULL;
}
