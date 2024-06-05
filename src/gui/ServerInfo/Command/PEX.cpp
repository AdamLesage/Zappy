/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#include "PEX.hpp"

Zappy::PEX::PEX()
{
}

Zappy::PEX::~PEX()
{
}

void Zappy::PEX::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
