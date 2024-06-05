/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PNW
*/

#include "PNW.hpp"

Zappy::PNW::PNW()
{
}

Zappy::PNW::~PNW()
{
}

void Zappy::PNW::askCommand(int socket, std::vector<std::string> args)
{
    if (socket == -1 || args.size() != 1)
        throw std::invalid_argument("Invalid socket for PNW command");
    // Doesnt need to ask data to the server
    return;
}