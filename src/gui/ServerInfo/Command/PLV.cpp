/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PLV
*/

#include "PLV.hpp"

Zappy::PLV::PLV()
{
}

Zappy::PLV::~PLV()
{
}

void Zappy::PLV::askCommand(int socket, std::vector<std::string> args)
{
    std::string command = "PLV " + args[0] + "\n";
    write(socket, command.c_str(), command.length());
}
