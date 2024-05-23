/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** init_server
*/

#include "../../include/server/server.h"

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
    core->socket_config.server_socket = init_socket(4000);
    core->socket_config.sockfd = 
        bind_socket(&core->socket_config.server_socket);
}
