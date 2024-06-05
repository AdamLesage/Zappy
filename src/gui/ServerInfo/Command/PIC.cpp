/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIC
*/

#include "PIC.hpp"

Zappy::PIC::PIC()
{
}

Zappy::PIC::~PIC()
{
}

void Zappy::PIC::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
