/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pin
*/

#include "server.h"

void pin(core_t *core, int fd, char **command)
{
    int player_fd = atoi(command[1]);
    player_info_t *player_info = find_player(&core->players, player_fd);

    if (len_array(command) != 2) {
        send_response("sbp\n", fd);
        return;
    }
    if (player_info != NULL) {
        pin_two(core, fd, player_info);
    } else {
        send_response("sbp\n", fd);
    }
}

void pin_two(core_t *core, int fd, player_info_t *player_info)
{
    inventory_t *inventory = player_info->inventory;

    send_response("pin ", fd);
    send_response_int(player_info->fd, fd);
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
    pin_three(core, fd, inventory);
}

void pin_three(core_t *core, int fd, inventory_t *inventory)
{
    send_response_int(inventory->nb_mendiane, fd);
    send_response(" ", fd);
    send_response_int(inventory->nb_phiras, fd);
    send_response(" ", fd);
    send_response_int(inventory->nb_thystame, fd);
    send_response("\n", fd);
}
