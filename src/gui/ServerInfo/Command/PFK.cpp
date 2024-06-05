/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PFK
*/

#include "PFK.hpp"

Zappy::PFK::PFK()
{
}

Zappy::PFK::~PFK()
{
}

void Zappy::PFK::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
