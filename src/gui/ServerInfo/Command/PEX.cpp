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
    if (strncmp(message.c_str(), "pex", 3))
        return {};

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
    // return format std::vector<std::string> { "pex", "player_id" };
    std::vector<std::string> data = { "pex", args[1] };
    return data;
}

void Zappy::PEX::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() != 1)
        return;
    std::string str = "pex " + args[1] + "\n";
    write(socket, str.c_str(), str.length());
}
