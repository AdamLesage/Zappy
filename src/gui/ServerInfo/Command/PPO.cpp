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
T Zappy::PPO::execute(std::string message)
{
    if (strncmp(message.c_str(), "ppo", 3))
        return;

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
}

void Zappy::PPO::askCommand(int fd, std::vector<std::string> args)
{
    
    std::string message = "ppo\n"; // add player number
    write(fd, message.c_str(), message.size());
}
