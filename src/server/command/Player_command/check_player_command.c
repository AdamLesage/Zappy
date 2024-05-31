/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** check_player_command
*/

#include "server.h"

extern const command_list_t commands_player_list[];

void next_player_command(player_info_t *info)
{
    if (info->action_queue[0] != NULL) {
        info->timer_action = get_time_action(info->action_queue[0]);
    }
}

void execute_client_command(core_t *core, char *command, int fd)
{
    char **array_command = my_str_to_word_array(command, ' ');

    if (array_command == NULL) {
        return;
    }
    for (int i = 0; commands_player_list[i].name != NULL; i++) {
        if (strcmp(commands_player_list[i].name, array_command[0]) == 0) {
            commands_player_list[i].exe_command(core, fd, array_command);
            free_array(array_command);
            return;
        }
    }
    free_array(array_command);
}

void check_player_command(core_t *core)
{
    char *command = NULL;

    for (players_list_t *tmp = core->players.players_list;
        tmp != NULL; tmp = tmp->next) {
        if (tmp->player_info->timer_action == 0 &&
            tmp->player_info->action_queue[0] != NULL) {
            command = get_action_in_queue(&core->players, tmp->fd);
            execute_client_command(core, command, tmp->fd);
            next_player_command(tmp->player_info);
        }
    }
}
