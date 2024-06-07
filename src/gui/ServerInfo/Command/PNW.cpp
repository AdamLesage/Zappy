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


void Zappy::PNW::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                int timeUnit,
                                bool isRunning
)
{
    std::shared_ptr<Player> player = std::make_shared<Player>();
    player->setPlayerNumber(std::stoi(parsedData[1]));
    player->setPosition(std::stoi(parsedData[2]), std::stoi(parsedData[3]));
    player->setOrientation(std::stoi(parsedData[4]));
    player->setPlayerLevel(std::stoi(parsedData[5]));
    player->setTeamName(parsedData[6]);
    players.push_back(player);
}
