/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** lunch_server
*/

#include "../../include/server/server.h"

static void init_select_info(core_t *core, float delay)
{
    core->select_info.max_fd = core->socket_config.sockfd;
    core->select_info.tv.tv_sec = delay;
    core->select_info.tv.tv_usec = 0;
    FD_ZERO(&core->select_info.rfds);
    FD_SET(core->socket_config.sockfd, &core->select_info.rfds);
    FD_ZERO(&core->select_info.write_fds);
    FD_ZERO(&core->select_info.except_fds);
    core->select_info.fd_socket_control = core->socket_config.sockfd;
}

static void manage_select_notif(core_t *core, int retval)
{
    if (retval > 0) {
        get_client_command(core);
        connect_client(&core->select_info,
            &core->socket_config.server_socket);
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
    float period = 0;

    period = (float)1 / core->arguments.frequency;
    init_select_info(core, period);
    while (1) {
        update_select_info(&core->select_info, core->arguments.frequency);
        retval = select(core->select_info.max_fd + 1,
            &core->select_info.read_fds, NULL,
            &core->select_info.except_fds, &core->select_info.tv);
        if (FD_ISSET(STDIN_FILENO, &core->select_info.except_fds)) {
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
