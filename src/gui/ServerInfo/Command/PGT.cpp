/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PGT
*/

#include "PGT.hpp"

Zappy::PGT::PGT()
{
}

Zappy::PGT::~PGT()
{
}

void Zappy::PGT::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
