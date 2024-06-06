/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** BCT
*/

#include "BCT.hpp"

Zappy::BCT::BCT()
{
}

Zappy::BCT::~BCT()
{
}

void Zappy::BCT::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 1)
        throw std::invalid_argument("Invalid number of arguments for SGT command");
    std::string message = "bct " + args[1] + " " + args[2] + "\n";
    write(fd, message.c_str(), message.size());
}
