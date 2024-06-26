/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server_data
*/

#ifndef SERVER_DATA_H_
    #define SERVER_DATA_H_

    #include <stdbool.h>

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
    int nb_food;
} inventory_t;

typedef struct incantation_info_s {
    int pos_x;
    int pos_y;
    int *ids;
    int nb_players;
    int incantation_level;
    int incantation_timer;
} incantation_info_t;

typedef struct incantation_list_s {
    incantation_info_t *incantation_info;
    struct incantation_list_s *next;
} incantation_list_t;

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
    bool is_on_incantation;
    int id;
} player_info_t;

typedef struct players_list_s {
    int fd;
    player_info_t *player_info;
    struct players_list_s *next;
} players_list_t;

typedef struct players_s {
    int nb_client;
    int nb_teams;
    players_list_t *players_list;
    incantation_list_t *incantation_list;
    int current_id;
} players_t;

typedef struct eggs_s {
    char *team_name;
    int pos_x;
    int pos_y;
    int egg_id;
    struct eggs_s *next;
} eggs_t;

typedef struct tile_info_s {
    int pos_x;
    int pos_y;
    int nb_players;
    int nb_linemate;
    int nb_deraumere;
    int nb_sibur;
    int nb_mendiane;
    int nb_phiras;
    int nb_thystame;
    int nb_food;
} tile_info_t;

typedef struct tiles_list_s {
    int pos_x;
    int pos_y;
    tile_info_t *tile_info;
    struct tiles_list_s *next;
} tiles_list_t;

typedef struct map_s {
    int width;
    int height;
    int last_refille;
    tiles_list_t *tiles_list;
    eggs_t *eggs;
    int current_eggs_id;
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

enum Object {
    Food = 0,
    Linemate = 1,
    Deraumere = 2,
    Sibur = 3,
    Mendiane = 4,
    Phiras = 5,
    Thystame = 6,
    None = 7,
};

void init_map(map_t *map, arguments_t *arguments);
tile_info_t *find_tile(map_t *map, int x, int y);
bool put_player(map_t *map, int x, int y);
bool put_food(map_t *map, int x, int y);
bool put_linemate(map_t *map, int x, int y);
bool put_sibur(map_t *map, int x, int y);
bool put_mendiane(map_t *map, int x, int y);
bool put_phiras(map_t *map, int x, int y);
bool put_thystame(map_t *map, int x, int y);
bool put_eggs(map_t *map, int x, int y, char *team_name);
bool put_deraumere(map_t *map, int x, int y);
bool remove_food(map_t *map, int x, int y);
bool remove_player(map_t *map, int x, int y);
bool remove_linemate(map_t *map, int x, int y);
bool remove_sibur(map_t *map, int x, int y);
bool remove_deraumere(map_t *map, int x, int y);
bool remove_mendiane(map_t *map, int x, int y);
bool remove_phiras(map_t *map, int x, int y);
bool remove_thystame(map_t *map, int x, int y);
bool remove_eggs(map_t *map, int x, int y, char *team_name);
int find_number_eggs_on_team(eggs_t *eggs, char *team);

void init_players(players_t *players, arguments_t *arguments);
bool add_player(map_t *map, players_t *players, int fd,
    char *team_name);
player_info_t *find_player(players_t *player, int fd);
player_info_t *find_player_by_id(players_t *player, int id);
bool delete_player(map_t *map, players_t *players, int fd);
void move_player(map_t *map, players_t *player, int fd);
void move_player2(map_t *map, players_t *player, int fd,
    enum Orientation orientation);
void turn_left(players_t *players, int fd);
void turn_right(players_t *players, int fd);
int *get_pos(players_t *players, int fd);
int get_level(players_t *players, int fd);
inventory_t *get_inventory(players_t *players, int fd);
char *get_player_team(players_t *players, int fd);
int find_nb_player_on_team(players_t *players, char *team_name);
void add_action_in_queue(players_t *players, int fd, char *action);
char *get_action_in_queue(players_t *players, int fd);
bool put_on_inventory(players_t *players, enum Object object,
    int fd);
bool remove_from_inventory(players_t *players, enum Object object,
    int fd);
bool remove_from_inventory_2(player_info_t *info, enum Object object);
int get_player_k(player_info_t *player_info, int x, int y,
    arguments_t *arguments);
int nb_player_at_level(players_list_t *player_list, int level,
    int x, int y);

#endif /* !SERVER_DATA_H_ */
