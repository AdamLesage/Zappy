/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** inventory
*/

#include "server.h"

static char **get_inventory_info(inventory_t *inventory_struct)
{
    char **inventory_info = malloc(sizeof(char *) * 8);

    inventory_info[0] = int_to_str(inventory_struct->nb_food);
    inventory_info[1] = int_to_str(inventory_struct->nb_linemate);
    inventory_info[2] = int_to_str(inventory_struct->nb_deraumere);
    inventory_info[3] = int_to_str(inventory_struct->nb_sibur);
    inventory_info[4] = int_to_str(inventory_struct->nb_mendiane);
    inventory_info[5] = int_to_str(inventory_struct->nb_phiras);
    inventory_info[6] = int_to_str(inventory_struct->nb_thystame);
    inventory_info[7] = NULL;
    return (inventory_info);
}

static int get_len_inventory(char **inventory_info)
{
    int len = 0;

    len += strlen("[ food ");
    len += strlen(", linemate ");
    len += strlen(", deraumere ");
    len += strlen(", sibur ");
    len += strlen(", mendiane ");
    len += strlen(", phiras ");
    len += strlen(", thystame ");
    len += strlen(" ]\n");
    for (int i = 0; inventory_info[i] != NULL; i++) {
        len += strlen(inventory_info[i]);
    }
    return (len);
}

static char *set_str_from_inventory_info(char **inventory_info,
    int len_inventory)
{
    char *str = NULL;

    str = malloc(sizeof(char) * len_inventory + 1);
    str[0] = '\0';
    strcat(str, "[ food ");
    strcat(str, inventory_info[0]);
    strcat(str, ", linemate ");
    strcat(str, inventory_info[1]);
    strcat(str, ", deraumere ");
    strcat(str, inventory_info[2]);
    strcat(str, ", sibur ");
    strcat(str, inventory_info[3]);
    strcat(str, ", mendiane ");
    strcat(str, inventory_info[4]);
    strcat(str, ", phiras ");
    strcat(str, inventory_info[5]);
    strcat(str, ", thystame ");
    strcat(str, inventory_info[6]);
    strcat(str, " ]\n");
    return (str);
}

void inventory(core_t *core, int fd, char **command)
{
    inventory_t *inventory_struct = get_inventory(&core->players, fd);
    char **inventory_info = get_inventory_info(inventory_struct);
    int len_inventory = get_len_inventory(inventory_info);
    char *str = NULL;

    if (command == NULL)
        return;
    str = set_str_from_inventory_info(inventory_info, len_inventory);
    add_to_send_buffer(&core->network, str, fd);
    free_array(inventory_info);
    free(str);
}
