/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** incantation
*/

#include "server.h"

static int *get_incantation_players_ids(player_info_t *player_info,
    players_t *players, int nb_player)
{
    int *ids = malloc(sizeof(int) * (nb_player + 1));
    int index = 0;

    for (players_list_t *tmp = players->players_list;
        tmp != NULL; tmp = tmp->next) {
        if (tmp->player_info->level == player_info->level &&
            tmp->player_info->is_on_incantation == false &&
            player_info->pos_x == tmp->player_info->pos_x &&
            player_info->pos_y == tmp->player_info->pos_y) {
            ids[index] = tmp->player_info->id;
            index++;
            ids[index] = -1;
            tmp->player_info->is_on_incantation = true;
            send_response("Elevation underway\n", tmp->fd);
        }
    }
    return ids;
}

static incantation_info_t *init_incantation_info(player_info_t *player_info,
    players_t *players)
{
    incantation_info_t *info = malloc(sizeof(incantation_info_t));

    info->pos_x = player_info->pos_x;
    info->pos_y = player_info->pos_y;
    info->incantation_level = player_info->level;
    info->incantation_timer = 300;
    info->nb_players = nb_player_at_level(players->players_list,
        info->incantation_level,
        info->pos_x, info->pos_y);
    info->ids = get_incantation_players_ids(player_info, players,
        info->nb_players);
    return info;
}

void start_incantation(core_t *core, int fd)
{
    player_info_t *player_info = find_player(&core->players, fd);
    incantation_list_t *new_incantation = NULL;
    tile_info_t *tile_info = find_tile(&core->map, player_info->pos_x,
        player_info->pos_y);

    if (incantation_is_valide(tile_info, core->players.players_list,
        player_info->level)) {
        new_incantation = malloc(sizeof(incantation_list_t));
        new_incantation->incantation_info =
            init_incantation_info(player_info, &core->players);
        new_incantation->next = core->players.incantation_list;
        core->players.incantation_list = new_incantation;
        pic(&core->players, new_incantation->incantation_info);
    } else {
        send_response("ko\n", fd);
    }
}

static void delete_incantation2(core_t *core,
    incantation_info_t *incantation_info)
{
    incantation_list_t *deleted_incantation = NULL;

    for (incantation_list_t *tmp = core->players.incantation_list;
        tmp->next != NULL; tmp = tmp->next) {
        if (tmp->next->incantation_info->incantation_level ==
            incantation_info->incantation_level &&
            tmp->next->incantation_info->pos_x == incantation_info->pos_x &&
            tmp->next->incantation_info->pos_y == incantation_info->pos_y &&
            tmp->next->incantation_info->incantation_timer == 0) {
            deleted_incantation = tmp->next;
            tmp->next = tmp->next->next;
            free(deleted_incantation->incantation_info->ids);
            free(deleted_incantation->incantation_info);
            free(deleted_incantation);
            return;
        }
    }
    return;
}

static void delete_incantation(core_t *core,
    incantation_info_t *incantation_info)
{
    incantation_list_t *deleted_incantation = NULL;
    incantation_list_t *tmp = core->players.incantation_list;

    if (tmp == NULL) {
        return;
    }
    if (tmp->incantation_info->incantation_level ==
        incantation_info->incantation_level &&
        tmp->incantation_info->pos_x == incantation_info->pos_x &&
        tmp->incantation_info->pos_y == incantation_info->pos_y &&
        tmp->incantation_info->incantation_timer == 0) {
        deleted_incantation = core->players.incantation_list;
        core->players.incantation_list = core->players.incantation_list->next;
        free(deleted_incantation->incantation_info->ids);
        free(deleted_incantation->incantation_info);
        free(deleted_incantation);
        return;
    }
    return delete_incantation2(core, incantation_info);
}

static void incantation_end_success(tile_info_t *tile_info,
    incantation_info_t *incantation_info, core_t *core)
{
    player_info_t *info = NULL;

    incantation_destroy_stone(tile_info, incantation_info->incantation_level);
    for (int i = 0; incantation_info->ids[i] != -1; i++) {
        info = find_player_by_id(&core->players, incantation_info->ids[i]);
        if (info != NULL) {
            info->level++;
            send_response("Current level: ", info->fd);
            send_response_int(info->level, info->fd);
            send_response("\n", info->fd);
        }
        plv_event(&core->players, info);
        pie(&core->players, tile_info->pos_x, tile_info->pos_y, true);
    }
}

static void incantation_end_failure(incantation_info_t *incantation_info,
    core_t *core)
{
    player_info_t *info = NULL;

    for (int i = 0; incantation_info->ids[i] != -1; i++) {
        info = find_player_by_id(&core->players, incantation_info->ids[i]);
        if (info != NULL)
            send_response("ko\n", info->fd);
    }
    pie(&core->players, incantation_info->pos_x, incantation_info->pos_y,
        false);
}

void incantation(core_t *core, incantation_info_t *incantation_info)
{
    tile_info_t *tile_info = find_tile(&core->map, incantation_info->pos_x,
        incantation_info->pos_y);
    player_info_t *info = NULL;

    for (int i = 0; incantation_info->ids[i] != -1; i++) {
        info = find_player_by_id(&core->players, incantation_info->ids[i]);
        if (info != NULL)
            info->is_on_incantation = false;
    }
    if (incantation_is_valide(tile_info, core->players.players_list,
        incantation_info->incantation_level)) {
        incantation_end_success(tile_info, incantation_info, core);
    } else {
        incantation_end_failure(incantation_info, core);
    }
    delete_incantation(core, incantation_info);
}
