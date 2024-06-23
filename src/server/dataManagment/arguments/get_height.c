/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_height
*/

#include "../../../../include/server/server.h"

/**
 * @brief Get the height from the arguments
 *
 * @param argv The arguments
 * @param index The index of the arguments
 * @return int The height
 */
int get_height(const char **argv, int *index)
{
    int height = 0;

    if (argv[*index + 1] == NULL) {
        print_usage("height missing number");
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        print_usage("height must be a number");
    }
    height = atoi(argv[*index]);
    if (height < 10 || height > 30) {
        print_usage("height must be > 10 and < 30");
    }
    return (height);
}
