/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_player_k
*/

#include "server.h"

static int *get_player_orientation(enum Orientation orientation)
{
    int *orientation_x_y = malloc(sizeof(int) * 2);

    orientation_x_y[0] = 0;
    orientation_x_y[1] = 0;
    if (orientation == N)
        orientation_x_y[0] = -1;
    if (orientation == S)
        orientation_x_y[0] = 1;
    if (orientation == W)
        orientation_x_y[1] = -1;
    if (orientation == E)
        orientation_x_y[1] = 1;
    return (orientation_x_y);
}

static int *find_shortest_path(player_info_t *player_info, int x, int y,
    arguments_t *arguments)
{
    int *vector = malloc(sizeof(int) * 2);

    if (vector == NULL) {
        return (NULL);
    }
    vector[0] = y - player_info->pos_y;
    vector[1] = x - player_info->pos_x;
    if (player_info->pos_x < arguments->width / 2 && abs(((arguments->width
        - x) + player_info->pos_x) - x) < abs(vector[1]))
        vector[1] = ((arguments->width - x) + player_info->pos_x) - x;
    if (player_info->pos_x > arguments->width / 2 && abs(((arguments->width
        - player_info->pos_x) + x) - x) < abs(vector[1]))
        vector[1] = ((arguments->width - player_info->pos_x) + x) - x;
    if (player_info->pos_y < arguments->height / 2 && abs(((arguments->height
        - y) + player_info->pos_y) - y) < abs(vector[0]))
        vector[0] = (player_info->pos_y - (arguments->height - y));
    if (player_info->pos_y > arguments->height / 2 && abs(((arguments->height
        - player_info->pos_y) + y) - y) < abs(vector[0]))
        vector[0] = ((arguments->height - player_info->pos_y) + y) - y;
    return (vector);
}

static int compute_angle(int *vector1, int *vector2)
{
    float s = vector1[0] * vector2[0] + vector1[1] * vector2[1];
    float u = sqrt(pow(vector1[0], 2) + pow(vector1[1], 2));
    float v = sqrt(pow(vector2[0], 2) + pow(vector2[1], 2));
    float angle = acos(s / u * v) * (180 / 3.14159265358979323846);

    if (vector1[0] < 0 && vector2[1] > 0) {
        angle += 180;
    }
    if (vector1[0] > 0 && vector2[1] < 0) {
        angle += 180;
    }
    if (vector1[1] < 0 && vector2[0] > 0) {
        angle += 180;
    }
    if (vector1[1] > 0 && vector2[0] < 0) {
        angle += 180;
    }
    return (angle);
}

int get_player_k(player_info_t *player_info, int x, int y,
    arguments_t *arguments)
{
    int *vector = find_shortest_path(player_info, x, y, arguments);
    int *orientation = get_player_orientation(player_info->orientation);
    float angle = 0;
    float angle2 = 22.5;

    if (vector == NULL || orientation == NULL)
        return (-1);
    if (player_info->pos_x == x && player_info->pos_y == y) {
        return (0);
    }
    angle = compute_angle(vector, orientation);
    if (angle < 22.5 || angle > (360 - 22.5)) {
        return (1);
    }
    for (double i = 2; i != 9; i++) {
        if (angle >= angle2 && angle <= angle2 + 45)
            return (i);
        angle2 += 45;
    }
    return (-1);
}
