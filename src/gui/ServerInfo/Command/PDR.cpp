/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PDR
*/

#include "PDR.hpp"

Zappy::PDR::PDR()
{
}

Zappy::PDR::~PDR()
{
}

void Zappy::PDR::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
