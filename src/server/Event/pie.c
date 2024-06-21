/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pie
*/

#include "server.h"

void pie(core_t *core, int x, int y, bool state)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->player_info->team_name, "GRAPHIC") == 0) {
            add_to_send_buffer(&core->network, "pie ", tmp->fd);
            add_int_to_send_buffer(&core->network, x, tmp->fd);
            add_to_send_buffer(&core->network, " ", tmp->fd);
            add_int_to_send_buffer(&core->network, y, tmp->fd);
            add_to_send_buffer(&core->network, " ", tmp->fd);
            add_int_to_send_buffer(&core->network, state, tmp->fd);
            add_to_send_buffer(&core->network, "\n", tmp->fd);
        }
    }
}
