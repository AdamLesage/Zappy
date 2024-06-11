/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** authentification
*/

#include "server.h"

static int get_id_eggs(eggs_t *eggs, char *team_name)
{
    if (eggs == NULL) {
        return (false);
    }
    for (eggs_t *tmp = eggs; tmp != NULL; tmp = tmp->next) {
        if (strcmp(team_name, tmp->team_name) == 0) {
            return (tmp->egg_id);
        }
    }
    return (-1);
}

void player_authentification(core_t *core, char *command, int fd)
{
    int eggs_used = -1;

    for (int i = 0; core->arguments.name_teams[i] != NULL; i++) {
        if (strcmp(core->arguments.name_teams[i], command) == 0) {
            eggs_used = get_id_eggs(core->map.eggs, command);
            add_player(&core->map, &core->players, fd, command);
            send_response(int_to_str(core->arguments.nb_client -
                find_nb_player_on_team(&core->players, command)), fd);
            send_response("\n", fd);
            send_response(int_to_str(core->arguments.width), fd);
            send_response(" ", fd);
            send_response(int_to_str(core->arguments.height), fd);
            send_response("\n", fd);
            pnw(&core->players, core->players.players_list->player_info);
            pin_event(&core->players, core->players.players_list->player_info);
            ebo(&core->players, eggs_used);
            return;
        }
    }
    send_response("ko\n", fd);
}

void graphic_authentification(core_t *core, char *command, int fd)
{
    add_player(&core->map, &core->players, fd, command);
    send_response("msz", fd);
    send_response(int_to_str(core->arguments.width), fd);
    send_response(" ", fd);
    send_response(int_to_str(core->arguments.height), fd);
    send_response("\n", fd);
}

void authentification(core_t *core, char *command, int fd)
{
    if (strcmp(command, "GRAPHIC") == 0) {
        graphic_authentification(core, command, fd);
    } else {
        player_authentification(core, command, fd);
    }
}
