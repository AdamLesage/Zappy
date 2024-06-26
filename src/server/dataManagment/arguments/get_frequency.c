/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_frequency
*/

#include "../../../../include/server/server.h"

/**
 * @brief Get the frequency from the arguments
 *
 * @param argv The arguments
 * @param index The index of the arguments
 * @return int The frequency
 */
int get_frequency(const char **argv, int *index)
{
    int frequency = 0;

    if (argv[*index + 1] == NULL) {
        print_usage("no frequency");
    }
    (*index)++;
    if (str_isnum((char *) argv[*index]) == false) {
        print_usage("frequency must be a number");
    }
    frequency = atoi(argv[*index]);
    if (frequency <= 1 || frequency > 10000) {
        print_usage("frequency must be > 1 and <= 10000");
    }
    return (frequency);
}
