/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** SEG
*/

#include "SEG.hpp"

Zappy::SEG::SEG()
{
}

Zappy::SEG::~SEG()
{
}

void Zappy::SEG::applyChanges(std::vector<std::string> parsedData,
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
    (void)players; // unused
    (void)eggs; // unused
    (void)timeUnit; // unused
    (void)isRunning; // unused
    (void)teams; // unused
    // parsedData vector { "seg", "timeUnit" }

    if (parsedData.size() != 2)
        throw Zappy::CommandError("Invalid number of arguments for SEG command", "SEG");

    isRunning = false;
}
