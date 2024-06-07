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
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                std::vector<std::string> &teams,
                                int &timeUnit,
                                bool &isRunning
)
{
    (void)size_map; // unused
    (void)tiles; // unused
    (void)eggs; // unused
    (void)timeUnit; // unused
    (void)isRunning; // unused
    (void)teams; // unused    
    // parsedData vector { "pdi", "playerNumber" }
    if (parsedData.size() != 2)
        throw Zappy::CommandError("Invalid number of arguments for PIC command", "PIC");

    try {
        for (auto &player : players) {
            if (player.get()->getPlayerNumber() == std::stoi(parsedData[1])) {
                players.erase(std::remove(players.begin(), players.end(), player), players.end());
                break;
            }
        }
    } catch (std::exception &e) {
        throw Zappy::CommandError("Invalid arguments for PIC command", "PIC");
    }
}
