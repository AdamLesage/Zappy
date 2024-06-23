/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** alloc_buffer
*/

#include "server.h"

/**
 * @brief Category: Utils | Allocates a buffer
 *
 * @param buffer The buffer to allocate
 * @param size_to_add The size to add
 * @return char* The buffer
 */
char *alloc_buffer(char *buffer, int size_to_add)
{
    if (buffer == NULL) {
        buffer = malloc(sizeof(char) * size_to_add + 1);
        buffer[0] = '\0';
    } else {
        buffer = realloc(buffer, sizeof(char) *
            (strlen(buffer) + size_to_add + 1));
    }
    return (buffer);
}
