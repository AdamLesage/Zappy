/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TNA
*/

#include "TNA.hpp"

Zappy::TNA::TNA()
{
}

Zappy::TNA::~TNA()
{
}

void Zappy::TNA::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 1)
        throw std::invalid_argument("Invalid number of arguments for TNA command");
    std::string message = "tna\n";
    write(fd, message.c_str(), message.size());
}
