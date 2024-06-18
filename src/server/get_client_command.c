/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_client_command
*/

#include "../../include/server/server.h"

static void disconnect_client(int readbite, int fd_client, core_t *core)
{
    if (readbite == 0) {
        printf("Client %d disconnected\n", fd_client);
    } else
        perror("read");
    close(fd_client);
    delete_player(&core->map, &core->players, fd_client);
    FD_CLR(fd_client, &core->select_info.rfds);
}

static char *get_command(core_t *core, int fd_client)
{
    size_t readbite;
    char buf[500];

    if (fd_client == core->select_info.fd_socket_control)
        return (NULL);
    for (int i = 0; i != 500; i++)
        buf[i] = '\0';
    readbite = read(fd_client, buf, sizeof(buf));
    if (readbite <= 0) {
        disconnect_client(readbite, fd_client, core);
        return (NULL);
    } else {
        buf[readbite - 1] = '\0';
    }
    return (strdup(buf));
}

static void set_player_command(core_t *core, player_info_t *info,
    char *command)
{
    if (info->action_queue[0] == NULL) {
        if (strcmp(command, "Incantation") == 0) {
            start_incantation(core, info->fd);
            return;
        }
        if (strcmp(command, "Fork") == 0) {
            pfk(&core->players, info->id);
        }
        info->timer_action = get_time_action(command);
    }
    add_action_in_queue(&core->players, info->fd, command);
}

static void choose_type_command(char *command, player_info_t *info,
    core_t *core, char *team_name)
{
    if (strcmp(team_name, "GRAPHIC") == 0) {
        execute_gui_command(core, command, info->fd);
    } else {
        set_player_command(core, info, command);
    }
}

void check_command(core_t *core, int fd, char *command)
{
    player_info_t *info = find_player(&core->players, fd);
    char *team_name = NULL;
    char **array_command = NULL;

    if (command == NULL) {
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

void get_client_command(core_t *core)
{
    char *command = NULL;

    for (int i = 0; i <= core->select_info.max_fd; i++) {
        if (FD_ISSET(i, &core->select_info.temp_fds)) {
            command = get_command(core, i);
            check_command(core, i, command);
        }
        if (command != NULL) {
            free(command);
            command = NULL;
        }
    }
}
