/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PGT
*/

#include "PGT.hpp"

Zappy::PGT::PGT()
{
}

Zappy::PGT::~PGT()
{
}

std::vector<std::string> Zappy::PGT::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "pgt", 3))
        return {};

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
    // return format std::vector<std::string> { "pgt", "player_nb", "resource_nb" };
    std::vector<std::string> data = { "pgt", args[1], args[2] };
    return data;
}

void Zappy::PGT::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
