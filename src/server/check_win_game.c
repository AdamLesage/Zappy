/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** check_win_game
*/

#include "server.h"

static bool check_win_for_team(players_t *players, char *team_name)
{
    int nb = 0;

    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (tmp->player_info->level == 8 &&
            strcmp(team_name, tmp->player_info->team_name) == 0) {
            nb++;
        }
    }
    if (nb >= 6) {
        return (true);
    }
    return (false);
}

void check_win_game(core_t *core)
{
    for (int i = 0; core->arguments.name_teams[i] != NULL; i++) {
        if (check_win_for_team(&core->players,
            core->arguments.name_teams[i])) {
            seg(&core->players, core->arguments.name_teams[i]);
            return;
        }
    }
}
