/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** client_command
*/

#include "server.h"

const command_list_t commands_gui_list[] = {
    {"msz", &msz, 1, 0},
    {"bct", &bct, 3, 0},
    {"mct", &mct, 1, 0},
    {"tna", &tna, 1, 0},
    {"ppo", &ppo, 2, 0},
    {"plv", &plv, 2, 0},
    {"pin", &pin, 2, 0},
    {"sgt", &sgt, 1, 0},
    {"sst", &sst, 2, 0},
    {NULL, NULL, 0, 0}
};
