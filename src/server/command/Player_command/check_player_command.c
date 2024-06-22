/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** check_player_command
*/

#include "server.h"

extern const command_list_t commands_player_list[];

static void next_player_command(player_info_t *info, core_t *core)
{
    if (info->action_queue[0] != NULL) {
        if (strcmp(info->action_queue[0], "Incantation") == 0) {
            start_incantation(core, info->fd);
            return;
        }
        if (strcmp(info->action_queue[0], "Fork") == 0) {
            pfk(core, info->id);
        }
        info->timer_action = get_time_action(info->action_queue[0]);
    }
}

static void execute_client_command(core_t *core, char *command, int fd)
{
    char **array_command = my_str_to_word_array(command, ' ');

    if (array_command == NULL ||
        strcmp("Incantation", array_command[0]) == 0) {
        return;
    }
    for (int i = 0; commands_player_list[i].name != NULL; i++) {
        if (strcmp(commands_player_list[i].name, array_command[0]) == 0) {
            commands_player_list[i].exe_command(core, fd, array_command);
            free_array(array_command);
            return;
        }
    }
    add_to_send_buffer(&core->network, "ko\n", fd);
    free_array(array_command);
}

static void check_end_incantation(core_t *core)
{
    for (incantation_list_t *tmp = core->players.incantation_list;
        tmp != NULL; tmp = tmp->next) {
        if (tmp->incantation_info->incantation_timer == 0) {
            incantation(core, tmp->incantation_info);
            check_end_incantation(core);
            return;
        } else {
            tmp->incantation_info->incantation_timer--;
        }
    }
}

static void get_and_execute_players_command(core_t *core, player_info_t *info)
{
    char *command = NULL;

    if (info->is_on_incantation == true)
        return;
    if (info->timer_action == 0 &&
        info->action_queue[0] != NULL) {
        command = get_action_in_queue(&core->players, info->fd);
        execute_client_command(core, command, info->fd);
        next_player_command(info, core);
    } else {
        info->timer_action--;
    }
    if (command != NULL) {
        free(command);
        command = NULL;
    }
}

void check_player_command(core_t *core)
{
    check_end_incantation(core);
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        get_and_execute_players_command(core, tmp->player_info);
    }
}
