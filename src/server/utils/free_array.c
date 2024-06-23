/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myftp-romain.chevallier
** File description:
** free_array
*/

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Category: Utils | Free an array
 *
 * @param array The array to free
 */
void free_array(char **array)
{
    if (array != NULL) {
        for (int i = 0; array[i] != NULL; i++) {
            free(array[i]);
        }
        free(array);
    }
}

/**
 * @brief Category: Utils | Free an array
 *
 * @param array The array to free
 */
void free_array2(char **array)
{
    if (array != NULL) {
        for (int i = 0; array[i] != NULL; i++) {
            free(array[i]);
        }
    }
}
