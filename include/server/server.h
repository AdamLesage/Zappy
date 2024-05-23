/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <netinet/ip.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include "server_data.h"

typedef struct select_info_s {
    fd_set rfds;
    fd_set temp_fds;
    int max_fd;
    struct timeval tv;
    int fd_socket_control;
} select_info_t;

typedef struct socket_config_s {
    struct sockaddr_in server_socket;
    int sockfd;
} socket_config_t;

typedef struct core_s {
    socket_config_t socket_config;
    select_info_t select_info;
    arguments_t arguments;
} core_t;

void init_core(const int argc, const char **argv, core_t *core);
void get_arguments(arguments_t *arguments, const int argc, const char **argv);
int get_port(const char **argv, int *index);
void init_server(core_t *core);
void close_server(core_t *core);
void lunch_server(core_t *core);
void connect_client(select_info_t *select_info,
    struct sockaddr_in *server_socket);
void get_client_command(core_t *core);
bool str_isnum(char *str);

#endif /* !SERVER_H_ */
