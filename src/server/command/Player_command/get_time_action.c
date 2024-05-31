/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_time_action
*/

#include "server.h"

extern const command_list_t commands_player_list[];

int get_time_action(char *command)
{
    char **array_command = my_str_to_word_array(command, ' ');

    if (array_command == NULL) {
        return 0;
    }
    for (int i = 0; commands_player_list[i].name != NULL; i++) {
        if (strcmp(commands_player_list[i].name, array_command[0]) == 0) {
            free_array(array_command);
            return commands_player_list[i].time;
        }
    }
    free_array(array_command);
    return (0);
}
