/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** close_server
*/

#include "../../include/server/server.h"

static void free_player(players_list_t *players)
{
    if (players == NULL) {
        return;
    }
    if (players->next != NULL) {
        free_player(players->next);
    }
    free_array2(players->player_info->action_queue);
    free(players->player_info->team_name);
    free(players->player_info->inventory);
    free(players->player_info);
    free(players);
}

static void free_incantation(incantation_list_t *incantation)
{
    if (incantation == NULL) {
        return;
    }
    if (incantation->next != NULL) {
        free_incantation(incantation->next);
    }
    free(incantation->incantation_info->ids);
    free(incantation->incantation_info);
    free(incantation);
}

static void free_map(tiles_list_t *tile)
{
    if (tile == NULL) {
        return;
    }
    if (tile->next != NULL) {
        free_map(tile->next);
    }
    free(tile->tile_info);
    free(tile);
}

static void free_eggs(eggs_t *eggs)
{
    if (eggs == NULL) {
        return;
    }
    if (eggs->next != NULL) {
        free_eggs(eggs->next);
    }
    free(eggs->team_name);
    free(eggs);
}

static void free_network(client_list_t *network)
{
    if (network == NULL) {
        return;
    }
    if (network->next != NULL) {
        free_network(network->next);
    }
    if (network->client_info->buffer_read != NULL) {
        free(network->client_info->buffer_read);
    }
    if (network->client_info->buffer_send != NULL) {
        free(network->client_info->buffer_send);
    }
    free(network->client_info);
    free(network);
}

void close_server(core_t *core)
{
    printf("server shutdown\n");
    free_player(core->players.players_list);
    free_incantation(core->players.incantation_list);
    free_map(core->map.tiles_list);
    free_eggs(core->map.eggs);
    free_array(core->arguments.name_teams);
    free_network(core->network.client_list);
    close(core->network.select_info.fd_socket_control);
    exit(0);
}
