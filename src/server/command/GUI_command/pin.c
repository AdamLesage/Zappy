/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pin
*/

#include "server.h"

void pin(core_t *core, int fd, char **command)
{
    int player_id = atoi(command[1]);
    player_info_t *player_info = find_player_by_id(&core->players, player_id);

    if (len_array(command) != 2) {
        add_to_send_buffer(&core->network, "sbp\n", fd);
        return;
    }
    if (player_info != NULL) {
        pin_two(&core->network, fd, player_info);
    } else {
        add_to_send_buffer(&core->network, "sbp\n", fd);
    }
}

void pin_event(network_t *network, players_t *players,
    player_info_t *player_info)
{
    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            pin_two(network, tmp->fd, player_info);
        }
    }
}

void pin_two(network_t *network, int fd, player_info_t *player_info)
{
    inventory_t *inventory = player_info->inventory;

    add_to_send_buffer(network, "pin ", fd);
    add_int_to_send_buffer(network, player_info->id, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, player_info->pos_x, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, player_info->pos_y, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, inventory->nb_food, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, inventory->nb_linemate, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, inventory->nb_deraumere, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, inventory->nb_sibur, fd);
    add_to_send_buffer(network, " ", fd);
    pin_three(network, fd, inventory);
}

void pin_three(network_t *network, int fd, inventory_t *inventory)
{
    add_int_to_send_buffer(network, inventory->nb_mendiane, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, inventory->nb_phiras, fd);
    add_to_send_buffer(network, " ", fd);
    add_int_to_send_buffer(network, inventory->nb_thystame, fd);
    add_to_send_buffer(network, "\n", fd);
}
