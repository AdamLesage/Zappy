/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIC
*/

#include "PIC.hpp"

Zappy::PIC::PIC()
{
}

Zappy::PIC::~PIC()
{
}

std::vector<std::string> Zappy::PIC::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "pic", 3))
        return {};

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
    // return format std::vector<std::string> { "pic", "x_pos", "y_pos", "player_id", "player_id", ... };
    std::vector<std::string> data = { "pic" };
    for (std::size_t i = 1; i < args.size(); i++)
        data.push_back(args[i]);
    return data;
}

void Zappy::PIC::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}