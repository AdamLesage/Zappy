/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** is_know_player_command
*/

#include "server.h"

extern const command_list_t commands_player_list[];

bool is_know_player_command(char *command)
{
    char **array_command = my_str_to_word_array(command, ' ');

    if (array_command == NULL) {
        return (false);
    }
    for (int i = 0; commands_player_list[i].name != NULL; i++) {
        if (strcmp(commands_player_list[i].name, array_command[0]) == 0) {
            return (true);
        }
    }
    return (false);
}
