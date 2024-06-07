/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** set
*/

#include "server.h"

static bool set_on_map(int *pos, enum Object object, map_t *map)
{
    switch (object) {
        case Food:
            return put_food(map, pos[0], pos[1]);
        case Linemate:
            return put_linemate(map, pos[0], pos[1]);
        case Deraumere:
            return put_deraumere(map, pos[0], pos[1]);
        case Sibur:
            return put_sibur(map, pos[0], pos[1]);
        case Mendiane:
            return put_mendiane(map, pos[0], pos[1]);
        case Phiras:
            return put_phiras(map, pos[0], pos[1]);
        case Thystame:
            return put_thystame(map, pos[0], pos[1]);
        case None:
            return (false);
    }
    return (false);
}

void set(core_t *core, int fd, char **command)
{
    int *pos = get_pos(&core->players, fd);
    enum Object object = string_to_object(command[1]);

    if (remove_fom_inventory(&core->players, object, fd) == false) {
        send_response("ko\n", fd);
    }
    set_on_map(pos, object, &core->map);
    send_response("ok\n", fd);
}
