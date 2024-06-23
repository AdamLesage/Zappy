/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** set_command
*/

#include "server.h"

/**
 * @brief Add the action in the queue of the player
 *
 * @param players
 * @param fd
 * @param command
 */
static void set_player_queue(core_t *core, player_info_t *info,
    char *command)
{
    if (info->action_queue[0] == NULL) {
        if (strcmp(command, "Incantation") == 0) {
            start_incantation(core, info->fd);
            return;
        }
        if (strcmp(command, "Fork") == 0) {
            pfk(core, info->id);
        }
        info->timer_action = get_time_action(command);
    }
    printf("receive: %s\n", command);
    add_action_in_queue(&core->players, info->fd, command);
}

/**
 * @brief Choose the type of command
 *
 * @param command
 * @param info
 * @param core
 * @param team_name
 */
static void choose_type_command(char *command, player_info_t *info,
    core_t *core, char *team_name)
{
    if (strcmp(team_name, "GRAPHIC") == 0) {
        execute_gui_command(core, command, info->fd);
    } else {
        set_player_queue(core, info, command);
    }
}

void set_command(core_t *core, int fd, char *command)
{
    player_info_t *info = find_player(&core->players, fd);
    char *team_name = NULL;
    char **array_command = NULL;

    if (command == NULL || command[0] == '\n') {
        return;
    }
    if (info == NULL) {
        authentification(core, command, fd);
    } else {
        team_name = get_player_team(&core->players, fd);
        array_command = my_str_to_word_array(command, '\n');
        for (int i = 0; array_command[i] != NULL; i++) {
            choose_type_command(array_command[i], info, core, team_name);
        }
        free(team_name);
        free_array(array_command);
    }
}
