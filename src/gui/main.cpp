/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** main
*/

#include <iostream>
#include <string.h>
#include "Interface/Interface.hpp"
#include "ServerInfo/GuiConnect.hpp"
#include <array>
#include "ServerInfo/ConnectError.hpp"
#include "ServerInfo/Command/CommandError.hpp"

std::array<std::string, 2> recup_args(int ac, char **av)
{
    std::string port;
    std::string machine;

    for (int i = 0; i < ac; i++) {
        if (strcmp(av[i], "-p") == 0) {
            if (av[i + 1] == NULL) {
                std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
                exit(84);
            } else {
                port = av[i + 1];
            }
        }
        if (strcmp(av[i], "-h") == 0) {
            if (av[i + 1] == NULL) {
                std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
                exit(84);
            } else {
                machine = av[i + 1];
            }
        }
    }
    return {port, machine};
}

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
        return 84;
    }
    if (strcmp(av[1], "-help") == 0) {
        std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
        return 0;
    }
    std::array<std::string, 2> args = recup_args(ac, av);
    try {
        Zappy::Interface interface;
        std::shared_ptr<GuiConnect> gui_connect = std::make_shared<GuiConnect>(args[0], args[1]);
        interface.loop(gui_connect);
    } catch (const Zappy::ConnectError &e) {
        std::cerr << "Error: " << e.what() << std::endl << "Location: " << e.where() << std::endl;
        return 84;
    } catch (const Zappy::InterfaceError &e) {
        std::cerr << "Error: " << e.what() << std::endl << "Location: " << e.where() << std::endl;
        return 84;
    }
    return 0;
}