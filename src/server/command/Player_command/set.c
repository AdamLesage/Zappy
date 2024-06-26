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
    player_info_t *info = NULL;

    if (remove_from_inventory(&core->players, object, fd) == false) {
        free(pos);
        add_to_send_buffer(&core->network, "ko\n", fd);
        return;
    }
    info = find_player(&core->players, fd);
    set_on_map(pos, object, &core->map);
    add_to_send_buffer(&core->network, "ok\n", fd);
    pdr(core, info->id, object);
    pin_event(&core->network, &core->players, info);
    bct_event(core, pos[0], pos[1]);
    free(pos);
}
