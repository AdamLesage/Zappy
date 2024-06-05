/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIE
*/

#include "PIE.hpp"

Zappy::PIE::PIE()
{
}

Zappy::PIE::~PIE()
{
}

void Zappy::PIE::askCommand(int socket, std::vector<std::string> args)
{
    std::string command = "pie " + args[0] + "\n";
    write(socket, command.c_str(), command.length());
}
