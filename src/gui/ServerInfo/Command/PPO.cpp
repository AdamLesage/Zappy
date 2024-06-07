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

void Zappy::PPO::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                int timeUnit,
                                bool isRunning
)
{
    (void) size_map;
    (void) tiles;
    (void) eggs;
    (void) timeUnit;
    (void) isRunning;
    
    int playerNumber = std::stoi(parsedData[1]);
    int x = std::stoi(parsedData[2]);
    int y = std::stoi(parsedData[3]);
    int orientation = std::stoi(parsedData[4]);
    for (auto &player : players) {
        if (player->getPlayerNumber() == playerNumber) {
            player->setPosition(x, y);
            player->setOrientation(orientation);
        }
    }
}
