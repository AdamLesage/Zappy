/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** SGT
*/

#include "SGT.hpp"

Zappy::SGT::SGT()
{
}

Zappy::SGT::~SGT()
{
}

void Zappy::SGT::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 1)
        throw std::invalid_argument("Invalid number of arguments for SGT command");
    std::string message = "sgt\n";
    write(fd, message.c_str(), message.size());
}
