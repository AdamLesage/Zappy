/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PDI
*/

#include "PDI.hpp"

Zappy::PDI::PDI()
{
}

Zappy::PDI::~PDI()
{
}

void Zappy::PDI::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::shared_ptr<Zappy::Tile>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs
)
{
    (void)size_map; // unused
    (void)tiles; // unused
    (void)eggs; // unused
    // parsedData vector { "pdi", "playerNumber" }
    if (parsedData.size() != 2)
        throw std::invalid_argument("Invalid number of arguments for PIC command");

    try {
        for (auto &player : players) {
            if (player.get()->getPlayerNumber() == std::stoi(parsedData[1])) {
                players.erase(std::remove(players.begin(), players.end(), player), players.end());
                break;
            }
        }
    } catch (std::exception &e) {
        throw std::invalid_argument("Invalid arguments for PIC command");
    }
}
