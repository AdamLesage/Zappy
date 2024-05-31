/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** str_is_num
*/

#include <stdbool.h>

bool str_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > '9' || str[i] < '0') {
            return (false);
        }
    }
    return (true);
}
