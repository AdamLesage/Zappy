/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PNW
*/

#include "PNW.hpp"

Zappy::PNW::PNW()
{
}

Zappy::PNW::~PNW()
{
}

std::vector<std::string> Zappy::PNW::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "pnw", 3))
        return {};
    // receive : pnw N X Y O L N\n
    std::vector<std::string> args = my_str_to_line_array((char *)message.c_str()); // vector of strings like : { "pnw, N, X, Y, O, L, N\n" }
    std::vector<std::string> connection;

    connection.push_back(args[0].substr(4, args[0].size() - 4)); // remove "pnw " from the string
    connection.push_back(args[1]); // x_pos
    connection.push_back(args[2]); // y_pos
    connection.push_back(args[3]); // orientation
    connection.push_back(args[4]); // level
    connection.push_back(args[5].substr(0, args[5].size() - 1)); // remove "\n" from the string

    // return format std::vector<std::string> { "pnw", "playerNumber", "x_pos", "y_pos", "orientation", "level", "teamName" };
    return connection;
}

void Zappy::PNW::askCommand(int socket, std::vector<std::string> args)
{
    if (socket == -1 || args.size() != 1)
        throw std::invalid_argument("Invalid socket for PNW command");
    // Doesnt need to ask data to the server
    return;
}