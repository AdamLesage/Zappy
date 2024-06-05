/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PPO
*/

#include "PPO.hpp"

Zappy::PPO::PPO()
{
}

Zappy::PPO::~PPO()
{
}

template<typename T>
T Zappy::PPO::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "ppo", 3))
        return;

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
    if (args.size() != 5)
        throw std::invalid_argument("Invalid number of arguments for PPO command");

    // return format std::vector<std::string> { "ppo", "playerNumber", "x_pos", "y_pos", "orientation" };
    std::string response = "ppo " + args[1] + " " + args[2] + " " + args[3] + " " + args[4] + "\n";
    return response;
}

void Zappy::PPO::askCommand(int fd, std::vector<std::string> args)
{
    std::string playerNumber = args[1];
    std::string message = "ppo " + playerNumber + "\n";
    write(fd, message.c_str(), message.size());
}
