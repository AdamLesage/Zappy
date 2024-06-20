/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** network_data
*/

#ifndef NETWORK_DATA_H_
#define NETWORK_DATA_H_

    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <netinet/ip.h>

typedef struct select_info_s {
    fd_set rfds;
    fd_set read_fds;
    fd_set write_fds;
    fd_set except_fds;
    int max_fd;
    struct timeval tv;
    int fd_socket_control;
} select_info_t;

typedef struct socket_config_s {
    struct sockaddr_in server_socket;
    int sockfd;
} socket_config_t;

typedef struct client_info_s {
    int fd;
    char *buffer_read;
    char *buffer_send;
} client_info_t;

typedef struct client_list_s {
    int fd;
    client_info_t *client_info;
    struct client_list_s *next;
} client_list_t;

typedef struct network_s {
    client_list_t *client_list;
    socket_config_t socket_config;
    select_info_t select_info;
} network_t;

bool add_client_on_network(network_t *network, int fd);
bool delete_client_of_network(network_t *network, int fd);
client_info_t *find_client(network_t *network, int fd);

#endif /* !NETWORK_DATA_H_ */
