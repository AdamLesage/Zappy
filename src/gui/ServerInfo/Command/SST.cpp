/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** SST
*/

#include "SST.hpp"

Zappy::SST::SST()
{
}

Zappy::SST::~SST()
{
}

void Zappy::SST::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 2)
        throw std::invalid_argument("Invalid number of arguments for SST command");
        // response format "SSt T\n"
    std::string timeUnit = args[1];
    std::string message = "SST " + timeUnit + "\n";
    write(fd, message.c_str(), message.size());
}
