/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** send_response
*/

#include "unistd.h"
#include "string.h"

void send_response(char *response, int fd)
{
    write(fd, response, strlen(response));
}
