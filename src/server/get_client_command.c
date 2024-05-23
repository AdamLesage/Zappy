/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_client_command
*/

#include "../../include/server/server.h"

void get_command(core_t *core, int fd_client)
{
    size_t readbite;
    char buf[500];

    printf("client request\n");
    if (fd_client == core->select_info.fd_socket_control) {
        return;
    }
    readbite = read(fd_client, buf, sizeof(buf));
    if (readbite <= 0) {
        if (readbite == 0) {
            printf("Client %d disconnected\n", fd_client);
        } else
            perror("read");
        close(fd_client);
        FD_CLR(fd_client, &core->select_info.rfds);
    } else {
        buf[readbite] = '\0';
        printf("reiceive Command: %s\n", buf);
    }
}

void get_client_command(core_t *core)
{
    for (int i = 0; i <= core->select_info.max_fd; i++) {
        if (FD_ISSET(i, &core->select_info.temp_fds)) {
            get_command(core, i);
        }
    }
}
