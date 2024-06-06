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
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                int timeUnit,
                                bool isRunning
)
{
    (void)size_map; // unused
    (void)tiles; // unused
    (void)players; // unused
    (void)timeUnit; // unused
    (void)isRunning; // unused
    // parsedData vector { "edi", "eggNumber" }

    if (parsedData.size() != 2)
        throw Zappy::CommandError("Invalid number of arguments for PFK command", "PFK");

    try {
        for (auto &egg : eggs) {
            if (egg->getPlayerNumber() == std::stoi(parsedData[1])) {
                eggs.erase(std::remove(eggs.begin(), eggs.end(), egg), eggs.end());
                break;
            }
        }
    } catch (std::exception &e) {
        throw Zappy::CommandError("Invalid arguments for PFK command", "PFK");
    }
}
