/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server_data
*/

#ifndef SERVER_DATA_H_
    #define SERVER_DATA_H_

enum Orientation {
    N = 1,
    E = 2,
    S = 3,
    W = 4,
};

typedef struct inventory_s {
    int nb_linemate;
    int nb_deraumere;
    int nb_sibur;
    int nb_mendiane;
    int nb_phiras;
    int nb_thystame;
} inventory_t;

typedef struct player_info_s {
    int pos_x;
    int pos_y;
    int level;
    inventory_t *inventory;
    char *action_queue[10];
    char *last_action;
    int timer_action;
    enum Orientation orientation;
    int fd;
    char *team_name;
    int last_feed;
} player_info_t;

typedef struct players_list_s {
    int fd;
    player_info_t player_info;
    players_list_t *next;
} players_list_t;

typedef struct players_s {
    int nb_client;
    int nb_teams;
    players_list_t *players_list;
} players_t;

typedef struct tiles_list_s {
    int pos_x;
    int pos_y;
    int nb_players;
    int nb_linemate;
    int nb_deraumere;
    int nb_sibur;
    int nb_mendiane;
    int nb_phiras;
    int nb_thystame;
    int nb_eggs;
    tiles_list_t *next;
} tiles_list_t;

typedef struct map_s {
    int width;
    int height;
    int last_refille;
    tiles_list_t *tiles_list;
} map_t;

typedef struct arguments_s {
    int port;
    int width;
    int height;
    char **name_teams;
    int nb_teams;
    int nb_client;
    int frequency;
} arguments_t;

void init_map(map_t *map, arguments_t *arguments);

#endif /* !SERVER_DATA_H_ */
