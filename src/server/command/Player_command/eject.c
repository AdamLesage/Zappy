/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** eject
*/

#include "server.h"

static bool delete_eggs_at(core_t *core, int x, int y, bool is_deleted)
{
    eggs_t *deleted_eggs = NULL;

    for (eggs_t *tmp = core->map.eggs; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->next->pos_x == x && tmp->next->pos_y == y) {
            deleted_eggs = tmp->next;
            tmp->next = tmp->next->next;
            edi(&core->players, deleted_eggs->egg_id);
            free(deleted_eggs);
            is_deleted = true;
        }
    }
    return (is_deleted);
}

static bool remove_eggs_at(core_t *core, int x, int y)
{
    eggs_t *deleted_eggs = NULL;
    bool is_deleted = false;

    if (core->map.eggs->pos_x == x && core->map.eggs->pos_y == y) {
        deleted_eggs = core->map.eggs;
        core->map.eggs = core->map.eggs->next;
        edi(&core->players, deleted_eggs->egg_id);
        free(deleted_eggs);
        is_deleted = true;
    }
    return delete_eggs_at(core, x, y, is_deleted);
}

void eject_player(core_t *core, int fd, player_info_t *info)
{
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (tmp->fd != fd && tmp->player_info->pos_x == info->pos_x &&
            tmp->player_info->pos_y == info->pos_y &&
            strcmp(tmp->player_info->team_name, "GRAPHIC") != 0) {
            move_player2(&core->map, &core->players, tmp->fd,
                info->orientation);
            send_response("eject: ", tmp->fd);
            send_response_int(get_player_k(tmp->player_info,
                info->pos_x, info->pos_y, &core->arguments), tmp->fd);
            send_response("\n", tmp->fd);
            send_ppo(core, tmp->player_info);
        }
    }
}

void eject(core_t *core, int fd, char **command)
{
    player_info_t *info = find_player(&core->players, fd);

    if (info == NULL || command == NULL)
        return;
    pex(&core->players, info);
    eject_player(core, fd, info);
    remove_eggs_at(core, info->pos_x, info->pos_y);
    send_response("ok\n", fd);
}
