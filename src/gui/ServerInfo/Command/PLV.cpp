/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PLV
*/

#include "PLV.hpp"

Zappy::PLV::PLV()
{
}

Zappy::PLV::~PLV()
{
}

void Zappy::PLV::askCommand(int socket, std::vector<std::string> args)
{
    std::string command = "PLV " + args[0] + "\n";
    write(socket, command.c_str(), command.length());
}

std::vector<std::string> Zappy::PLV::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "plv", 3))
        return {};
    std::vector<std::string> args = my_str_to_word_array((char *)message.c_str());
    std::vector<std::string> data;
    std::string player_nb = args[1];
    std::string player_level = args[2];

    data.push_back("plv");
    data.push_back(player_nb);
    data.push_back(player_level);
    // return format std::vector<std::string> { "plv", "player_nb", "player_level" };
    return data;
}
