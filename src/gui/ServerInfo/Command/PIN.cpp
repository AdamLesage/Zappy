/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIN
*/

#include "PIN.hpp"

Zappy::PIN::PIN()
{
}

Zappy::PIN::~PIN()
{
}

void Zappy::PIN::askCommand(int socket, std::vector<std::string> args)
{
    std::string command = "pin " + args[0] + "\n";
    write(socket, command.c_str(), command.length());
}
