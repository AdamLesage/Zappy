/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PFK
*/

#include "PFK.hpp"

Zappy::PFK::PFK()
{
}

Zappy::PFK::~PFK()
{
}

std::vector<std::string> Zappy::PFK::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "pfk", 3))
        return {};

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
    // return format std::vector<std::string> { "pgt", "player_nb" };
    std::vector<std::string> data = { "pfk", args[1] };
    return data;
}

void Zappy::PFK::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
