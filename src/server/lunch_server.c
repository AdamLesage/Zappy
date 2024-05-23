/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** lunch_server
*/

#include "../../include/server/server.h"

// int retval;
//     client_managment_t client_managment;
//     client_list_t *client_list = NULL;

//     init_client_managment(&client_managment, fd_socket_control, 1);
//     while (1) {
//         client_managment.tv.tv_sec = 1;
//         client_managment.tv.tv_usec = 0;
//         client_managment.temp_fds = client_managment.rfds;
//         retval = select(client_managment.max_fd + 1,
//             &client_managment.temp_fds, NULL, NULL, &client_managment.tv);
//         if (retval == -1) {
//             perror("error select");
//             exit(84);
//         }
//         creat_client(control_socket, &client_managment, &client_list, config);
//         manage_client(&client_managment, &client_list);
//     }

void init_client_managment(core_t *core, int delay)
{
    core->select_info.max_fd = core->socket_config.sockfd;
    core->select_info.tv.tv_sec = delay;
    core->select_info.tv.tv_usec = 0;
    FD_ZERO(&core->select_info.rfds);
    FD_SET(core->socket_config.sockfd, &core->select_info.rfds);
    core->select_info.fd_socket_control = core->socket_config.sockfd;
}

void lunch_server(core_t *core)
{
    int retval = 0;

    init_select_info(core);
    while(1) {
        core->select_info.tv.tv_sec = 1;
        core->select_info.tv.tv_usec = 0;
        core->select_info.temp_fds = core->select_info.rfds;
        retval = select(core->select_info.max_fd + 1,
            &core->select_info.temp_fds, NULL, NULL, &core->select_info.tv);
        if (retval == -1) {
            perror("error select");
            exit(84);
        }
        connect_client(&core->select_info, &core->socket_config.server_socket);
        get_client_command(core);
        // if (1) { /*the select is not declanched by a client*/
        //     execute_client_command();
        //     // reffil_map(core->map);
        // }
    }
}
