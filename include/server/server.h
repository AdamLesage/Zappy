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

    typedef struct socket_config_s {
        struct sockaddr_in my_sockaddr_in;
        int sockfd;
    } socket_config_t;

    typedef struct core_s {
        socket_config_t socket_config;    
    } core_t;

void init_core(const int argc, const char **argv, core_t *core);
void init_server(core_t *core);
void close_server(core_t *core);
void lunch_server(core_t *core);

#endif /* !SERVER_H_ */
