/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_client_command
*/

#include "../../include/server/server.h"

static void disconnect_client(int readbite, int fd_client, core_t *core)
{
    player_info_t *info = find_player(&core->players, fd_client);

    if (readbite == 0) {
        printf("Client %d disconnected\n", fd_client);
    } else
        perror("read");
    close(fd_client);
    FD_CLR(fd_client, &core->network.select_info.rfds);
    if (info != NULL) {
        pdi(core, info->id);
        delete_player(&core->map, &core->players, fd_client);
        enw(core, -1, core->map.eggs);
    }
    delete_client_of_network(&core->network, fd_client);
}

static char *read_socket(core_t *core, int fd_client)
{
    int readbite = 0;
    char *buf = NULL;

    buf = malloc(sizeof(char) * 2);
    readbite = read(fd_client, buf, 1);
    if (readbite <= 0) {
        disconnect_client(readbite, fd_client, core);
        free(buf);
        return (NULL);
    }
    if (readbite != 0) {
        buf[1] = '\0';
    }
    return (buf);
}

static bool read_client_socket(core_t *core, int fd_client)
{
    client_info_t *client_info = find_client(&core->network, fd_client);
    char *buf = NULL;

    if (client_info == NULL) {
        disconnect_client(0, fd_client, core);
        return (true);
    }
    client_info->buffer_read = alloc_buffer(client_info->buffer_read, 1);
    buf = read_socket(core, fd_client);
    if (buf == NULL)
        return (true);
    strcat(client_info->buffer_read, buf);
    if (buf[0] == '\n') {
        client_info->buffer_read[strlen(client_info->buffer_read) - 1] = '\0';
        set_command(core, fd_client, client_info->buffer_read);
        free(client_info->buffer_read);
        client_info->buffer_read = NULL;
    }
    free(buf);
    return (false);
}

void get_client_command(core_t *core)
{
    for (int i = 0; i <= core->network.select_info.max_fd; i++) {
        if (FD_ISSET(i, &core->network.select_info.read_fds) &&
            core->network.select_info.fd_socket_control != i) {
            read_client_socket(core, i);
        }
    }
}
