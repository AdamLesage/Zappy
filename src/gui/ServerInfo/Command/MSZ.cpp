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

template<typename T>
T Zappy::MSZ::execute(std::string message)
{
    if (strncmp(message.c_str(), "msz", 3))
        return;

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
    x = std::stoi(args[1]);
    y = std::stoi(args[2]);
    pair = std::pair<int, int>(x, y);
    return pair;
}

void Zappy::MSZ::askCommand(int fd, std::vector<std::string> args)
{
    std::string message = "msz\n"; // add map size
    write(fd, message.c_str(), message.size());
}
