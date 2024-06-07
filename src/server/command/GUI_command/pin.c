/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pin
*/

#include "server.h"

players_list_t *get_player(core_t *core, int fd)
{
    players_list_t *player = core->players.players_list;

    while (player != NULL) {
        if (player->fd == fd) {
            return player;
        }
        player = player->next;
    }
    return NULL;
}

void pin(core_t *core, int fd, char **command)
{
    int player_fd = atoi(command[1]);
    players_list_t *player = get_player(core, player_fd);

    if (len_array(command) != 2) {
        send_response("sbp\n", fd);
        return;
    }
    if (player != NULL) {
        pin_two(core, fd, player);
    } else {
        send_response("sbp\n", fd);
    }
}

void pin_two(core_t *core, int fd, players_list_t *player)
{
    player_info_t *player_info = player->player_info;
    inventory_t *inventory = player_info->inventory;

    send_response("pin ", fd);
    send_response_int(player->fd, fd);
    send_response(" ", fd);
    send_response_int(player_info->pos_x, fd);
    send_response(" ", fd);
    send_response_int(player_info->pos_y, fd);
    send_response(" ", fd);
    send_response_int(inventory->nb_food, fd);
    send_response(" ", fd);
    send_response_int(inventory->nb_linemate, fd);
    send_response(" ", fd);
    send_response_int(inventory->nb_deraumere, fd);
    send_response(" ", fd);
    send_response_int(inventory->nb_sibur, fd);
    send_response(" ", fd);
    pin_three(core, fd, player);
}

void pin_three(core_t *core, int fd, players_list_t *player)
{
    inventory_t *inventory = player->player_info->inventory;

    send_response_int(inventory->nb_mendiane, fd);
    send_response(" ", fd);
    send_response_int(inventory->nb_phiras, fd);
    send_response(" ", fd);
    send_response_int(inventory->nb_thystame, fd);
    send_response("\n", fd);
}
