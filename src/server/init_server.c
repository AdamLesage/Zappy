/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** init_server
*/

#include "../../include/server/server.h"

static void init_select_info(network_t *network, float delay)
{
    network->select_info.max_fd = network->socket_config.sockfd;
    network->select_info.tv.tv_sec = delay;
    network->select_info.tv.tv_usec = 0;
    FD_ZERO(&network->select_info.rfds);
    FD_SET(network->socket_config.sockfd, &network->select_info.rfds);
    FD_ZERO(&network->select_info.write_fds);
    FD_ZERO(&network->select_info.except_fds);
    network->select_info.fd_socket_control = network->socket_config.sockfd;
}

static struct sockaddr_in init_socket(int port)
{
    struct sockaddr_in server_socket;

    server_socket.sin_family = AF_INET;
    server_socket.sin_port = htons(port);
    server_socket.sin_addr.s_addr = INADDR_ANY;
    return (server_socket);
}

static int bind_socket(struct sockaddr_in *server_socket)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        write(2, "error sockets\n", strlen("error sockets\n"));
        exit(84);
    }
    if (bind(sockfd, (struct sockaddr *) &(*server_socket),
        sizeof(*server_socket))) {
        perror("bind");
        exit(84);
    }
    if (listen(sockfd, 100) == -1) {
        write(2, "errr listen\n", strlen("error listen\n"));
        exit(84);
    }
    return (sockfd);
};

void init_server(core_t *core)
{
    core->network.socket_config.server_socket =
        init_socket(core->arguments.port);
    core->network.socket_config.sockfd =
        bind_socket(&core->network.socket_config.server_socket);
    core->network.client_list = NULL;
    init_select_info(&core->network, 1);
}
