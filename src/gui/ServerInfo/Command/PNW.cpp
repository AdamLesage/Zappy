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
                                std::vector<std::string> &teams,
                                int timeUnit,
                                bool isRunning
)
{
    (void)size_map;
    (void)tiles;
    (void)eggs;
    (void)timeUnit;
    (void)isRunning;
    (void)teams;
    // parsedData = {"pnw", "playerNumber", "x", "y", "orientation", "level", "teamName"}
    if (parsedData.size() != 7)
        throw Zappy::CommandError("Invalid number of arguments for PNW command", "PNW");
    std::shared_ptr<Player> player = std::make_shared<Player>();
    player->setPlayerNumber(std::stoi(parsedData[1]));
    player->setPosition(std::stoi(parsedData[2]), std::stoi(parsedData[3]));
    player->setOrientation(std::stoi(parsedData[4]));
    player->setPlayerLevel(std::stoi(parsedData[5]));
    player->setTeamName(parsedData[6]);
    players.push_back(player);
}
