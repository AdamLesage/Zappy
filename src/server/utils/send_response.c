/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** send_response
*/

#include "server.h"

/**
 * @brief Category: Utils | Send the response to the client
 *
 * @param response The response to send
 * @param fd The file descriptor of the client
 */
void send_response(char *response, int fd)
{
    write(fd, response, strlen(response));
}

/**
 * @brief Category: Utils | Send the response to the client
 *
 * @param response The response to send
 * @param fd The file descriptor of the client
 */
void send_response_int(int response, int fd)
{
    char *str = NULL;

    str = int_to_str(response);
    write(fd, str, strlen(str));
    free(str);
}
