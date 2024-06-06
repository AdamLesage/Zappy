/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** EDI
*/

#include "EDI.hpp"

Zappy::EDI::EDI()
{
}

Zappy::EDI::~EDI()
{
}

void Zappy::EDI::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::shared_ptr<Zappy::Tile>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs
)
{
    (void)size_map; // unused
    (void)tiles; // unused
    (void)players; // unused
    // parsedData vector { "edi", "eggNumber" }

    if (parsedData.size() != 2)
        throw std::invalid_argument("Invalid number of arguments for PFK command");

    try {
        for (auto &egg : eggs) {
            if (egg->getPlayerNumber() == std::stoi(parsedData[1])) {
                eggs.erase(std::remove(eggs.begin(), eggs.end(), egg), eggs.end());
                break;
            }
        }
    } catch (std::exception &e) {
        throw std::invalid_argument("Invalid arguments for PFK command");
    }
}
