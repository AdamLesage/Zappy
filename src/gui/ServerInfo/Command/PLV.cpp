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

void Zappy::PLV::applyChanges(std::vector<std::string> parsedData,
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
    int level = std::stoi(parsedData[2]);
    for (auto &player : players) {
        if (player->getPlayerNumber() == playerNumber) {
            player->setPlayerLevel(level);
        }
    }
}