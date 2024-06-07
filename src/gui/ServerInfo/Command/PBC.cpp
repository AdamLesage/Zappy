/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PBC
*/

#include "PBC.hpp"

Zappy::PBC::PBC()
{
}

Zappy::PBC::~PBC()
{
}

void Zappy::PBC::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                std::vector<std::string> &teams,
                                int timeUnit,
                                bool isRunning
)
{
    (void)size_map;
    (void)tiles;
    (void)eggs;
    (void)teams;
    (void)timeUnit;
    (void)isRunning;
    std::string message = parsedData[1];
    std::string playerNumber = parsedData[0];
    for (auto &player : players) {
        if (player->getPlayerNumber() == std::stoi(playerNumber)) {
            player->setMessage(message);
            break;
        }
    }
}