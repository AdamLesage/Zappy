/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_client_command
*/

#include "../../include/server/server.h"

char *get_command(core_t *core, int fd_client)
{
    size_t readbite;
    char buf[500];

    if (fd_client == core->select_info.fd_socket_control)
        return (NULL);
    readbite = read(fd_client, buf, sizeof(buf));
    if (readbite <= 0) {
        if (readbite == 0) {
            printf("Client %d disconnected\n", fd_client);
        } else
            perror("read");
        close(fd_client);
        delete_player(&core->map, &core->players, fd_client);
        FD_CLR(fd_client, &core->select_info.rfds);
        return (NULL);
    } else {
        buf[readbite] = '\0';
        printf("reiceive Command: %s\n", buf);
    }
    return (strdup(buf));
}

void set_player_command(players_t *players, player_info_t *info, char *command)
{
    if (!is_know_player_command(command)) {
        send_response("KO\n", info->fd);
    } else {
        if (info->action_queue[0] == NULL) {
            info->timer_action = get_time_action(command);
        }
        add_action_in_queue(players, info->fd, command);
    }
}

void check_command(core_t *core, int fd, char *command)
{
    player_info_t *info = find_player(&core->players, fd);

    if (info == NULL) {
        authentification(core, command, fd);
    } else if (strcmp(get_player_team(&core->players, fd), "GRAPHIC") == 0) {
        execute_gui_command(core, command, fd);
    } else {
        set_player_command(&core->players, info, command);
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
