/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIE
*/

#include "PIE.hpp"

Zappy::PIE::PIE()
{
}

Zappy::PIE::~PIE()
{
}

void Zappy::PIE::askCommand(int socket, std::vector<std::string> args)
{
    std::string command = "pie " + args[0] + "\n";
    write(socket, command.c_str(), command.length());
}

std::vector<std::string> Zappy::PIE::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "pie", 3))
        return {};
    std::vector<std::string> args = my_str_to_word_array((char *)message.c_str());
    std::vector<std::string> data;

    data.push_back("pie");
    data.push_back(args[1]); // x_pos
    data.push_back(args[2]); // y_pos
    data.push_back(args[3]); // result
    // return format std::vector<std::string> { "pie", "x_pos", "y_pos", "result" };
    return data;
}