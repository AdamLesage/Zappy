/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** str_is_num
*/

#include <stdbool.h>

/**
 * @brief Category: Utils | Check if a string is a number
 *
 * @param str The string to check
 * @return true The string is a number
 * @return false The string is not a number
 */
bool str_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > '9' || str[i] < '0') {
            return (false);
        }
    }
    return (true);
}
