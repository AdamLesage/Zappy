/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** client_command
*/

#include "server.h"

const command_list_t commands_player_list[] = {
    {"Forward", &forward, 1, 7},
    {"Right", &right, 1, 7},
    {"Left", &left, 1, 7},
    {"Look", &look, 1, 7},
    {"Inventory", &inventory, 1, 1},
    {"Broadcast", &broadcast, 2, 7},
    {"Connect_nbr", &connect_nbr, 1, 0},
    {"Fork", &ffork, 1, 42},
    {"Eject", &eject, 1, 7},
    {"Take", &take, 2, 7},
    {"Set", &set, 2, 7},
    {"Incantation", &incantation, 1, 300},
    {NULL, NULL, 0, 0}
};
