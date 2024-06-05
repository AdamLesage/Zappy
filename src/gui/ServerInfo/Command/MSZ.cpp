/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MSZ
*/

#include "MSZ.hpp"

Zappy::MSZ::MSZ()
{
}

Zappy::MSZ::~MSZ()
{
}

std::vector<std::string> Zappy::MSZ::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "msz", 3))
        return {};

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
    // return format std::vector<std::string> { "msz", "x", "y" };
    std::vector<std::string> pair = { "msz", args[1], args[2] };
    return pair;
}

void Zappy::MSZ::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 1)
        throw std::invalid_argument("Invalid number of arguments for MSZ command");
    std::string message = "msz\n"; // add map size
    write(fd, message.c_str(), message.size());
}
