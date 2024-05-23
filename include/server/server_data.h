/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server_data
*/

#ifndef SERVER_DATA_H_
    #define SERVER_DATA_H_

typedef struct arguments_s {
    int port;
    int width;
    int height;
    char **name_teams;
    int nb_client;
    int frequence;
} arguments_t;

#endif /* !SERVER_DATA_H_ */
