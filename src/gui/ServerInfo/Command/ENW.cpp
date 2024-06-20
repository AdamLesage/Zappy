/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ENW
*/

#include "ENW.hpp"

Zappy::ENW::ENW()
{
}

Zappy::ENW::~ENW()
{
}


void Zappy::ENW::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                std::vector<std::string> &teams,
                                int &timeUnit,
                                bool &isRunning
)
{
    (void)size_map;
    (void)tiles;
    (void)teams;
    (void)timeUnit;
    (void)isRunning;
    if (parsedData.size() != 5)
        throw Zappy::CommandError("Invalid number of arguments for ENW command", "ENW");
    std::shared_ptr<Egg> egg = std::make_shared<Egg>();
    egg->_eggNb = std::stoi(parsedData[1]);
    egg->setPlayerNumber(std::stoi(parsedData[2]));
    egg->setPosition(std::stoi(parsedData[3]), std::stoi(parsedData[4]));
    if (std::stoi(parsedData[2]) == -1) {
        egg->setTeamName("server");
    } else {
        std::shared_ptr<Player> playertt = std::make_shared<Player>();
        for (auto &player : players) {
            if (player->getPlayerNumber() == std::stoi(parsedData[2])) {
                playertt = player;
                break;
            }
        }
        egg->setTeamName(playertt->getTeamName());
    }
    eggs.push_back(egg);
}
