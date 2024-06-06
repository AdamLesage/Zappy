/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MSZ
*/

#include "MSZ.hpp"

Zappy::MSZ::MSZ()
{
}

Zappy::MSZ::~MSZ()
{
}

void Zappy::MSZ::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 1)
        throw std::invalid_argument("Invalid number of arguments for SGT command");
    std::string message = "msz\n";
    write(fd, message.c_str(), message.size());
}
