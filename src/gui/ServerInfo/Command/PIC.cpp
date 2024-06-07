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
    // parsedData vector { "pic", "x", "y", "level", "playerNumber", "playerNumber", ... }
    if (parsedData.size() < 5)
        throw Zappy::CommandError("Invalid number of arguments for PIC command", "PIC");

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
        throw Zappy::CommandError("Invalid arguments for PIC command", "PIC");
    }
}
