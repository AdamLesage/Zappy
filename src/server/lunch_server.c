/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** lunch_server
*/

#include "../../include/server/server.h"

void lunch_server(core_t *core)
{
    while(1) {
        select();
        connect_client(core);
        manage_client(core);
        if (1) { /*the select is not declanched by a client*/
            execute_client_command();
            // reffil_map(core->map);
        }
    }
}
