/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** EBO
*/

#include "EBO.hpp"

Zappy::EBO::EBO()
{
}

Zappy::EBO::~EBO()
{
}

void Zappy::EBO::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::shared_ptr<Zappy::Tile>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs
)
{
    (void)size_map; // unused
    (void)tiles; // unused
    // parsedData vector { "ebo", "eggNumber" }
    if (parsedData.size() != 2)
        throw std::invalid_argument("Invalid number of arguments for PIC command");

    try {
        std::shared_ptr<Zappy::Player> player = std::make_shared<Zappy::Player>();

        for (auto &egg : eggs) {
            if (egg.get()->getPlayerNumber() == std::stoi(parsedData[1])) {
                player->setPlayerNumber(egg->getPlayerNumber());
                player->setPosition(egg->getPosition()[0], egg->getPosition()[1]);
                player->setTeamName(egg->getTeamName());
                player->setPlayerLevel(1);
                player->setOrientation(0);
                players.push_back(player);
                eggs.erase(std::remove(eggs.begin(), eggs.end(), egg), eggs.end());
                break;
            }
        }

    } catch (std::exception &e) {
        throw std::invalid_argument("Invalid arguments for PIC command");
    }
}