/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PBC
*/

#include "PBC.hpp"

Zappy::PBC::PBC()
{
}

Zappy::PBC::~PBC()
{
}

std::vector<std::string> Zappy::PBC::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "pbc", 3))
        return {};

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
    // return format std::vector<std::string> { "pbc", "player_id", "message" };
    std::vector<std::string> data = { "pbc", args[1], args[2] };
    return data;
}

void Zappy::PBC::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() != 2)
        return;
    std::string str = "pbc " + args[1] + "\n";
    write(socket, str.c_str(), str.length());
}
