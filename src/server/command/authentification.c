/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** authentification
*/

#include "server.h"

void player_authentification(core_t *core, char *command, int fd)
{
    for (int i = 0; core->arguments.name_teams[i] != NULL; i++) {
        if (strcmp(core->arguments.name_teams[i], command) == 0) {
            add_player(&core->map, &core->players, fd, command);
            send_response(int_to_str(core->arguments.nb_client -
                find_nb_player_on_team(&core->players, command)), fd);
            send_response("\n", fd);
            send_response(int_to_str(core->arguments.width), fd);
            send_response(" ", fd);
            send_response(int_to_str(core->arguments.height), fd);
            send_response("\n", fd);
            return;
        }
    }
    send_response("ko\n", fd);
}

void authentification(core_t *core, char *command, int fd)
{
    if (strcmp(command, "GRAPHIC") == 0) {
    } else {
        player_authentification(core, command, fd);
    }
}
