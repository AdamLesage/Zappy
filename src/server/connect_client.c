/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** connect_client
*/

#include "../../include/server/server.h"

void connect_client(select_info_t *select_info,
    struct sockaddr_in *server_socket)
{
    unsigned int len = 0;
    int fd_new_client = 0;

    if (FD_ISSET(select_info->fd_socket_control, &select_info->read_fds)) {
        len = sizeof(server_socket);
        fd_new_client = accept(select_info->fd_socket_control,
            (struct sockaddr *)&(*server_socket), &len);
        if (fd_new_client == -1) {
            write(fd_new_client, "Ko\n", 3);
            return;
        }
        FD_SET(fd_new_client, &select_info->rfds);
        if (fd_new_client > select_info->max_fd)
            select_info->max_fd = fd_new_client;
        send_response("WELCOME\n", fd_new_client);
    }
}
