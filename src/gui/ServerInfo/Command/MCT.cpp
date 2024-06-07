/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MCT
*/

#include "MCT.hpp"

Zappy::MCT::MCT()
{
}

Zappy::MCT::~MCT()
{
}

void Zappy::MCT::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 1)
        throw Zappy::CommandError("Invalid number of arguments for SGT command", "MCT");
    std::string message = "MCT\n";
    write(fd, message.c_str(), message.size());
}
