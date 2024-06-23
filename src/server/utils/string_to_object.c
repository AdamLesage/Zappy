/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** string_to_object
*/

#include "server.h"

/**
 * @brief Category: Utils | Convert a string to an object
 *
 * @param str The string to convert
 * @return enum Object The object
 */
enum Object string_to_object(char *str)
{
    if (strcmp(str, "food") == 0)
        return Food;
    if (strcmp(str, "linemate") == 0)
        return Linemate;
    if (strcmp(str, "deraumere") == 0)
        return Deraumere;
    if (strcmp(str, "sibur") == 0)
        return Sibur;
    if (strcmp(str, "mendiane") == 0)
        return Mendiane;
    if (strcmp(str, "phiras") == 0)
        return Phiras;
    if (strcmp(str, "thystame") == 0)
        return Thystame;
    return (None);
}
