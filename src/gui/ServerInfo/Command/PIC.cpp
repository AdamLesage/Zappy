/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIC
*/

#include "PIC.hpp"

Zappy::PIC::PIC()
{
}

Zappy::PIC::~PIC()
{
}

void Zappy::PIC::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::shared_ptr<Zappy::Tile>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs
)
{
    (void)size_map; // unused
    (void)tiles; // unused
    (void)eggs; // unused
    // parsedData vector { "pic", "x", "y", "level", "playerNumber", "playerNumber", ... }
    if (parsedData.size() < 5)
        throw std::invalid_argument("Invalid number of arguments for PIC command");

    try {
        // Update player isIncanting status
        for (auto &player : players) {
            for (std::size_t i = 4; i < parsedData.size(); i++) {
                if (player.get()->getPlayerNumber() == std::stoi(parsedData[i])) {
                    player->setIsIncanting(true);
                    break;
                }
            }
        }
    } catch (std::exception &e) {
        throw std::invalid_argument("Invalid arguments for PIC command");
    }
}