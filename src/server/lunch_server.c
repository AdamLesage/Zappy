/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** lunch_server
*/

#include "../../include/server/server.h"

static void manage_select_notif(core_t *core, int retval)
{
    if (retval > 0) {
        connect_client(&core->network);
        get_client_command(core);
    } else {
        check_win_game(core);
        check_player_command(core);
        check_food_players(core);
        core->map.last_refille--;
        if (core->map.last_refille == 0) {
            refill_map(core);
        }
    }
}

static void update_select_info(select_info_t *select_info, int frequency)
{
    select_info->tv.tv_sec = 0;
    select_info->tv.tv_usec =
        ((float)1 / frequency) * 1000000;
    select_info->read_fds = select_info->rfds;
    select_info->write_fds = select_info->rfds;
    select_info->except_fds = select_info->rfds;
    FD_SET(STDIN_FILENO, &select_info->except_fds);
}

void lunch_server(core_t *core)
{
    int retval = 0;

    while (1) {
        update_select_info(&core->network.select_info,
            core->arguments.frequency);
        retval = select(core->network.select_info.max_fd + 1,
            &core->network.select_info.read_fds, NULL,
            &core->network.select_info.except_fds,
            &core->network.select_info.tv);
        if (FD_ISSET(STDIN_FILENO, &core->network.select_info.except_fds)) {
            close_server(core);
            exit(0);
        }
        if (retval == -1) {
            close_server(core);
            exit(84);
        }
        manage_select_notif(core, retval);
    }
}
