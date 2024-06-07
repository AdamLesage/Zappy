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
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                int timeUnit,
                                bool isRunning
)
{
    (void)size_map; // unused
    (void)tiles; // unused
    (void)timeUnit; // unused
    (void)isRunning; // unused
    // parsedData vector { "pfk", "playerNumber" }

    if (parsedData.size() != 2)
        throw Zappy::CommandError("Invalid number of arguments for PFK command", "PFK");

    try {
        std::shared_ptr<Zappy::Player> player = nullptr;
        for (auto &p : players) {
            if (p->getPlayerNumber() == std::stoi(parsedData[1])) {
                player = p;
                break;
            }
        }
        if (player == nullptr)
            throw Zappy::CommandError("Player not found", "PFK");
        std::shared_ptr<Zappy::Egg> egg = std::make_shared<Zappy::Egg>();
        egg->setPosition(player->getPosition()[0], player->getPosition()[1]);
        egg->setPlayerNumber(player->getPlayerNumber());
        egg->setTeamName(player->getTeamName());
        eggs.push_back(egg);
    } catch (std::exception &e) {
        throw Zappy::CommandError("Invalid arguments for PFK command", "PFK");
    }
}
