/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PDR
*/

#include "PDR.hpp"

Zappy::PDR::PDR()
{
}

Zappy::PDR::~PDR()
{
}

std::vector<std::string> Zappy::PDR::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "pdr", 3))
        return {};

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
    // return format std::vector<std::string> { "pdr", "player_nb", "resource_nb" };
    std::vector<std::string> data = { "pdr", args[1], args[2] };
    return data;
}

void Zappy::PDR::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
