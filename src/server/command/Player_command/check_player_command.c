/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** check_player_command
*/

#include "server.h"

extern const command_list_t commands_player_list[];

void next_player_command(player_info_t *info, core_t *core)
{
    if (info->action_queue[0] != NULL) {
        if (strcmp(info->action_queue[0], "Incantation") == 0) {
            start_incantation(core, info->fd);
            return;
        }
        if (strcmp(info->action_queue[0], "Fork") == 0) {
            pfk(&core->players, info->id);
        }
        info->timer_action = get_time_action(info->action_queue[0]);
    }
}

void execute_client_command(core_t *core, char *command, int fd)
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
    send_response("ko\n", fd);
    free_array(array_command);
}

void check_end_incantation(core_t *core)
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

void check_player_command(core_t *core)
{
    char *command = NULL;

    check_end_incantation(core);
    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (tmp->player_info->is_on_incantation == true) {
            continue;
        }
        if (tmp->player_info->timer_action == 0 &&
            tmp->player_info->action_queue[0] != NULL) {
            command = get_action_in_queue(&core->players, tmp->fd);
            execute_client_command(core, command, tmp->fd);
            next_player_command(tmp->player_info, core);
        } else {
            tmp->player_info->timer_action--;
        }
    }
}
