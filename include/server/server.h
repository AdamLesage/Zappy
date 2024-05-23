/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

typedef struct core_s {

} core_t;

void init_core(const int argc, const char **argv, core_t *core);
void init_server(core_t *core);
void close_server(core_t *core);
void lunch_server(core_t *core);

#endif /* !SERVER_H_ */
