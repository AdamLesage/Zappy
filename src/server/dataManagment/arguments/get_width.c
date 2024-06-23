/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_width
*/

#include "../../../../include/server/server.h"

/**
 * @brief Get the width from the arguments
 *
 * @param argv The arguments
 * @param index The index of the arguments
 * @return int The width
 */
int get_width(const char **argv, int *index)
{
    int width = 0;

    if (argv[*index + 1] == NULL) {
        print_usage("width number not found");
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        print_usage("width must be a number");
    }
    width = atoi(argv[*index]);
    if (width < 10 || width > 30) {
        print_usage("width must be >= 10 and <= 30");
    }
    return (width);
}
