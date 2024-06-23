/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** find_number_eggs_on_team
*/

#include "server.h"

/**
 * @brief Find the number of eggs on a team
 *
 * @param eggs The eggs
 * @param team The team
 * @return int The number of eggs
 */
int find_number_eggs_on_team(eggs_t *eggs, char *team)
{
    int number = 0;

    if (team == NULL) {
        return (-1);
    }
    for (eggs_t *tmp = eggs; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->team_name, team) == 0) {
            number++;
        }
    }
    return (number);
}
