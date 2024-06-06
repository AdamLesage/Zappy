/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PFK
*/

#include "PFK.hpp"

Zappy::PFK::PFK()
{
}

Zappy::PFK::~PFK()
{
}

void Zappy::PFK::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::shared_ptr<Zappy::Tile>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs
)
{
    (void)size_map; // unused
    (void)tiles; // unused
    // parsedData vector { "pfk", "playerNumber" }

    if (parsedData.size() != 2)
        throw std::invalid_argument("Invalid number of arguments for PFK command");

    try {
        std::shared_ptr<Zappy::Player> player = nullptr;
        for (auto &p : players) {
            if (p->getPlayerNumber() == std::stoi(parsedData[1])) {
                player = p;
                break;
            }
        }
        if (player == nullptr)
            throw std::invalid_argument("Player not found");
        std::shared_ptr<Zappy::Egg> egg = std::make_shared<Zappy::Egg>();
        egg->setPosition(player->getPosition()[0], player->getPosition()[1]);
        egg->setPlayerNumber(player->getPlayerNumber());
        egg->setTeamName(player->getTeamName());
        eggs.push_back(egg);
    } catch (std::exception &e) {
        throw std::invalid_argument("Invalid arguments for PFK command");
    }
}
