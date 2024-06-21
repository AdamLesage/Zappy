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
    #include <math.h>
    #include <signal.h>
    #include "server_data.h"
    #include "network_data.h"

typedef struct look_info_s {
    char *str;
    int *look_orientation;
    int level;
    player_info_t *player_info;
} look_info_t;

typedef struct core_s {
    arguments_t arguments;
    map_t map;
    players_t players;
    network_t network;
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
void connect_client(network_t *network);
void get_client_command(core_t *core);
bool str_isnum(char *str);
char *int_to_str(int nbr);
void send_response(char *response, int fd);
void send_response_int(int response, int fd);
void free_array(char **array);
void free_array2(char **array);
char **my_str_to_word_array(char *str, char separator);
int len_array(char **arr);
enum Object string_to_object(char *str);
char *alloc_buffer(char *buffer, int size_to_add);
void set_command(core_t *core, int fd, char *command);

void authentification(core_t *core, char *command, int fd);
int get_time_action(char *command);
void execute_gui_command(core_t *core, char *command, int fd);
bool is_know_player_command(char *command);
void check_player_command(core_t *core);
void check_food_players(core_t *core);
void refill_map(core_t *core);
void check_win_game(core_t *core);

void incantation(core_t *core, incantation_info_t *incantation_info);
bool incantation_is_valide(tile_info_t *info, players_list_t *players_list,
    int level);
void incantation_destroy_stone(tile_info_t *info, int level);
void start_incantation(core_t *core, int fd);
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
void bct_event(core_t *core, int x, int y);
void bct_two(core_t *core, int fd, tiles_list_t *current_tile);
void bct_three(core_t *core, int fd, tiles_list_t *current_tile);
void mct(core_t *core, int fd, char **command);
void mct_start(core_t *core, int fd);
void mct_event(core_t *core);
void msz(core_t *core, int fd, char **command);
void msz_start(core_t *core, int fd);
void pin(core_t *core, int fd, char **command);
void pin_two(network_t *network, int fd, player_info_t *player_info);
void pin_three(network_t *network, int fd, inventory_t *inventory);
void pin_event(network_t *network, players_t *players,
    player_info_t *player_info);
void plv(core_t *core, int fd, char **command);
void plv_start(network_t *network, int fd, player_info_t *player_info);
void plv_event(network_t *network, players_t *players,
    player_info_t *player_info);
void ppo(core_t *core, int fd, char **command);
void send_ppo(core_t *core, player_info_t *player_info);
void sgt(core_t *core, int fd, char **command);
void sgt_start(core_t *core, int fd);
void sst(core_t *core, int fd, char **command);
void tna(core_t *core, int fd, char **command);
void tna_start(core_t *core, int fd);

void pnw(players_t *players, player_info_t *player_info);
void send_pnw_info(player_info_t *player_info, int fd);
void pex(players_t *players, player_info_t *player_info);
void pbc(players_t *players, int id, char *message);
void pic(players_t *players, incantation_info_t *info);
void pie(players_t *players, int x, int y, bool state);
void pfk(players_t *players, int id);
void pdr(players_t *players, int id, enum Object object);
void pgt(players_t *players, int id, enum Object object);
void pdi(players_t *players, int id);
void enw(players_t *players, int player_id, eggs_t *eggs);
void send_enw_info(int player_id, eggs_t *eggs, int fd);
void ebo(players_t *players, int egg_id);
void edi(players_t *players, int egg_id);
void seg(players_t *players, char *team_name);
void smg(players_t *players, char *message);

#endif /* !SERVER_H_ */
