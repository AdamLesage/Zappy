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

void Zappy::PPO::askCommand(int fd, std::vector<std::string> args)
{
    std::string playerNumber = args[1];
    std::string message = "ppo " + playerNumber + "\n";
    write(fd, message.c_str(), message.size());
}
