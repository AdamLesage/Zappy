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
    map_t map;
    players_t players;
} core_t;

typedef struct command_list_s {
    char *name;
    void (*exe_command) (core_t *core, int fd, char **command);
    int nb_argv;
    int time;
} command_list_t;

void init_core(const int argc, const char **argv, core_t *core);
void get_arguments(arguments_t *arguments, const int argc, const char **argv);
void print_usage(char *error);
int get_port(const char **argv, int *index);
int get_width(const char **argv, int *index);
int get_height(const char **argv, int *index);
void get_teams_name(arguments_t *arguments, const char **argv, int *index);
int get_number_client_by_teams(const char **argv, int *index);
int get_frequency(const char **argv, int *index);
void init_server(core_t *core);
void close_server(core_t *core);
void lunch_server(core_t *core);
void connect_client(select_info_t *select_info,
    struct sockaddr_in *server_socket);
void get_client_command(core_t *core);
bool str_isnum(char *str);
char *int_to_str(int nbr);
void send_response(char *response, int fd);
void send_response_int(int response, int fd);
void free_array(char **array);
char **my_str_to_word_array(char *str, char separator);
int len_array(char **arr);

void authentification(core_t *core, char *command, int fd);
int get_time_action(char *command);
void execute_gui_command(core_t *core, char *command, int fd);
bool is_know_player_command(char *command);
void check_player_command(core_t *core);

void incantation(core_t *core, int fd, char **command);
void broadcast(core_t *core, int fd, char **command);
void connect_nbr(core_t *core, int fd, char **command);
void eject(core_t *core, int fd, char **command);
void ffork(core_t *core, int fd, char **command);
void forward(core_t *core, int fd, char **command);
void inventory(core_t *core, int fd, char **command);
void left(core_t *core, int fd, char **command);
void look(core_t *core, int fd, char **command);
void right(core_t *core, int fd, char **command);
void set(core_t *core, int fd, char **command);
void take(core_t *core, int fd, char **command);

void bct(core_t *core, int fd, char **command);
void mct(core_t *core, int fd, char **command);
void msz(core_t *core, int fd, char **command);
void pin(core_t *core, int fd, char **command);
void plv(core_t *core, int fd, char **command);
void ppo(core_t *core, int fd, char **command);
void sgt(core_t *core, int fd, char **command);
void sst(core_t *core, int fd, char **command);
void tna(core_t *core, int fd, char **command);

#endif /* !SERVER_H_ */
