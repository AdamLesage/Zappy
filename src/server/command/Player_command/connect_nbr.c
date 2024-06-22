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
    add_int_to_send_buffer(&core->network, connect_number, fd);
    add_to_send_buffer(&core->network, "\n", fd);
    free(team_name);
}
