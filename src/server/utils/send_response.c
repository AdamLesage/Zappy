/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** send_response
*/

#include "server.h"

void send_response(char *response, int fd)
{
    write(fd, response, strlen(response));
}

void send_response_int(int response, int fd)
{
    char *str = NULL;

    str = int_to_str(response);
    write(fd, str, strlen(str));
    free(str);
}
