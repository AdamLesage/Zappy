/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** init_server
*/

#include "../../include/server/server.h"

static struct sockaddr_in init_socket(int port)
{
    struct sockaddr_in my_sockaddr_in;

    my_sockaddr_in.sin_family = AF_INET;
    my_sockaddr_in.sin_port = htons(port);
    my_sockaddr_in.sin_addr.s_addr = INADDR_ANY;
    return (my_sockaddr_in);
}

static int bind_socket(struct sockaddr_in *my_sockaddr_in)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        write(2, "error sockets\n", strlen("error sockets\n"));
        exit(84);
    }
    if (bind(sockfd, (struct sockaddr *) &(*my_sockaddr_in),
        sizeof(*my_sockaddr_in))) {
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
    core->socket_config.my_sockaddr_in = init_socket(4000);
    core->socket_config.sockfd = 
        bind_socket(&core->socket_config.my_sockaddr_in);
}
