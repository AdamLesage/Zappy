/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** execute_GUI_command
*/

#include "server.h"

extern const command_list_t commands_gui_list[];

void execute_gui_command(core_t *core, char *command, int fd)
{
    char **array_command = my_str_to_word_array(command, ' ');

    if (array_command == NULL) {
        return;
    }
    for (int i = 0; commands_gui_list[i].name != NULL; i++) {
        if (strcmp(commands_gui_list[i].name, array_command[0]) == 0 &&
            len_array(array_command) == commands_gui_list[i].nb_argv) {
            commands_gui_list[i].exe_command(core, fd, array_command);
            free_array(array_command);
            return;
        }
    }
    send_response("suc\n", fd);
    free_array(array_command);
}
