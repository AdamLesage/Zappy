/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#include "PEX.hpp"

Zappy::PEX::PEX()
{
}

Zappy::PEX::~PEX()
{
}

std::vector<std::string> Zappy::PEX::receiveData(std::string message)
{
    if (message == "ko\n")
        return {"ko"};
    return {"ok"};
}

void Zappy::PEX::askCommand(int socket, std::vector<std::string> args)
{
    std::string str = "pex " + args[1] + "\n";
    write(socket, str.c_str(), str.length());
}
