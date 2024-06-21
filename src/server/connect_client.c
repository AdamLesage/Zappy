/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** connect_client
*/

#include "../../include/server/server.h"

void connect_client(network_t *network)
{
    unsigned int len = 0;
    int fd_new_client = 0;

    if (FD_ISSET(network->select_info.fd_socket_control,
        &network->select_info.read_fds)) {
        len = sizeof(network->socket_config.server_socket);
        fd_new_client = accept(network->select_info.fd_socket_control,
            (struct sockaddr *)&(network->socket_config.server_socket), &len);
        if (fd_new_client == -1) {
            write(fd_new_client, "Ko\n", 3);
            return;
        }
        FD_SET(fd_new_client, &network->select_info.rfds);
        if (fd_new_client > network->select_info.max_fd)
            network->select_info.max_fd = fd_new_client;
        add_client_on_network(network, fd_new_client);
        network->client_list->client_info->buffer_send = strdup("WELCOME\n");
    }
}
