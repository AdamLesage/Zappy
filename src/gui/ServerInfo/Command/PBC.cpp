/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PBC
*/

#include "PBC.hpp"

Zappy::PBC::PBC()
{
}

Zappy::PBC::~PBC()
{
}

void Zappy::PBC::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
