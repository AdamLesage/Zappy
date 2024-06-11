/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** take
*/

#include "server.h"

bool take_on_map(int *pos, enum Object object, map_t *map)
{
    switch (object) {
        case Food:
            return remove_food(map, pos[0], pos[1]);
        case Linemate:
            return remove_linemate(map, pos[0], pos[1]);
        case Deraumere:
            return remove_deraumere(map, pos[0], pos[1]);
        case Sibur:
            return remove_sibur(map, pos[0], pos[1]);
        case Mendiane:
            return remove_mendiane(map, pos[0], pos[1]);
        case Phiras:
            return remove_phiras(map, pos[0], pos[1]);
        case Thystame:
            return remove_thystame(map, pos[0], pos[1]);
        case None:
            return (false);
    }
    return (false);
}

void take(core_t *core, int fd, char **command)
{
    int *pos = get_pos(&core->players, fd);
    enum Object object = string_to_object(command[1]);
    player_info_t *info = NULL;

    if (take_on_map(pos, object, &core->map) == false) {
        send_response("ko\n", fd);
        return;
    }
    put_on_inventory(&core->players, object, fd);
    send_response("ok\n", fd);
    info = find_player(&core->players, fd);
    pgt(&core->players, info->id, object);
    pin_event(&core->players, info);
    bct_event(core, pos[0], pos[1]);
}
