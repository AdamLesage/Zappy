/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** connect_nbr
*/

#include "server.h"

void connect_nbr(core_t *core, int fd, char **command)
{
    char *team_name = get_player_team(&core->players, fd);
    int connect_number = find_number_eggs_on_team(core->map.eggs, team_name);

    if (command == NULL) {
        return;
    }
    send_response_int(connect_number, fd);
    send_response("\n", fd);
    free(team_name);
}
