/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIE
*/

#include "PIE.hpp"

Zappy::PIE::PIE()
{
}

Zappy::PIE::~PIE()
{
}

void Zappy::PIE::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                int timeUnit,
                                bool isRunning
)
{
    (void)size_map; // unused
    (void)tiles; // unused
    (void)eggs; // unused
    (void)timeUnit; // unused
    (void)isRunning; // unused
    // parsedData vector { "pie", "x", "y", "incantation result" }
    if (parsedData.size() != 4)
        throw Zappy::CommandError("Invalid number of arguments for PIC command", "PIC");

    try {
        // Update player isIncanting status
        std::string incantationResult = parsedData[3];
        for (std::size_t i = 0; i < players.size(); i++) {
            if (players[i]->getPosition()[0] == std::stoi(parsedData[1]) && // if playerX == incantationX
                players[i]->getPosition()[1] == std::stoi(parsedData[2]) && // if playerY == incantationY
                players[i]->isPlayerIncanting() == true) {
                players[i]->setIsIncanting(false);
                if (incantationResult == "ok") {
                    players[i]->setPlayerLevel(players[i]->getLevel() + 1);
                }
            }
        }
    } catch (std::exception &e) {
        throw Zappy::CommandError("Invalid arguments for PIC command", "PIC");
    }
}
