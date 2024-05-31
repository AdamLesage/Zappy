/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** find_nb_player_on_team
*/

#include "server.h"

int find_nb_player_on_team(players_t *players, char *team_name)
{
    int number = 0;

    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, team_name) == 0) {
            number++;
        }
    }
    return (number);
}
