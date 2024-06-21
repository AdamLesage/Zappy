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

static void create_player(core_t *core, char *command, int fd)
{
    int eggs_used = -1;

    eggs_used = get_id_eggs(core->map.eggs, command);
    if (add_player(&core->map, &core->players, fd, command)) {
        add_int_to_send_buffer(&core->network,
            find_number_eggs_on_team(core->map.eggs, command), fd);
        add_to_send_buffer(&core->network, "\n", fd);
        add_int_to_send_buffer(&core->network, core->arguments.width, fd);
        add_to_send_buffer(&core->network, " ", fd);
        add_int_to_send_buffer(&core->network, core->arguments.height, fd);
        add_to_send_buffer(&core->network, "\n", fd);
        pnw(&core->players, core->players.players_list->player_info);
        pin_event(&core->players, core->players.players_list->player_info);
        ebo(&core->players, eggs_used);
    } else {
        add_to_send_buffer(&core->network, "ko\n", fd);
    }
}

void player_authentification(core_t *core, char *command, int fd)
{
    for (int i = 0; core->arguments.name_teams[i] != NULL; i++) {
        if (strcmp(core->arguments.name_teams[i], command) == 0) {
            create_player(core, command, fd);
            return;
        }
    }
    send_response("ko\n", fd);
}

void graphic_authentification(core_t *core, char *command, int fd)
{
    add_player(&core->map, &core->players, fd, command);
    msz_start(core, fd);
    sgt_start(core, fd);
    mct_start(core, fd);
    tna_start(core, fd);
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") != 0) {
            send_pnw_info(tmp->player_info, fd);
            pin_two(fd, tmp->player_info);
            plv_start(fd, tmp->player_info);
        }
    }
    for (eggs_t *tmp = core->map.eggs; tmp != NULL; tmp = tmp->next) {
        send_enw_info(-1, tmp, fd);
    }
}

void authentification(core_t *core, char *command, int fd)
{
    if (strcmp(command, "GRAPHIC") == 0) {
        graphic_authentification(core, command, fd);
    } else {
        player_authentification(core, command, fd);
    }
}
