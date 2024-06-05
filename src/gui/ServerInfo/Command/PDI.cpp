/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PDI
*/

#include "PDI.hpp"

Zappy::PDI::PDI()
{
}

Zappy::PDI::~PDI()
{
}

void Zappy::PDI::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
