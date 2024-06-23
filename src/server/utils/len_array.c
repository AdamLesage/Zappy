/*
** EPITECH PROJECT, 2023
** len_array.c
** File description:
** len_array
*/

#include <stdlib.h>

/**
 * @brief Category: Utils | Get the length of an array
 *
 * @param arr The array
 * @return int The length of the array
 */
int len_array(char **arr)
{
    int len = 0;

    for (; arr[len] != NULL; len++) {
    }
    return (len);
}
