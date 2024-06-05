/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ENW
*/

#include "ENW.hpp"

Zappy::ENW::ENW()
{
}

Zappy::ENW::~ENW()
{
}

void Zappy::ENW::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
