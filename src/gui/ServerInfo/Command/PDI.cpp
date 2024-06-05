/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PDI
*/

#include "PDI.hpp"

Zappy::PDI::PDI()
{
}

Zappy::PDI::~PDI()
{
}

std::vector<std::string> Zappy::PDI::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "pdi", 3))
        return {};

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
    // return format std::vector<std::string> { "pdi", "player_id" };
    std::vector<std::string> data = { "pdi", args[1], args[2] };
    return data;
}

void Zappy::PDI::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
