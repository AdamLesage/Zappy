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
    (void)timeUnit; // unused
    (void)isRunning; // unused
    (void)teams; // unused    
    // parsedData vector { "ebo", "eggNumber" }

    if (parsedData.size() != 2)
        throw Zappy::CommandError("Invalid number of arguments for PIC command", "EBO");
    try {
        std::shared_ptr<Zappy::Player> player = std::make_shared<Zappy::Player>();

        for (auto &egg : eggs) {
            if (egg.get()->getEggNb() == std::stoi(parsedData[1])) {
                eggs.erase(std::remove(eggs.begin(), eggs.end(), egg), eggs.end());
                break;
            }
        }

    } catch (std::exception &e) {
        throw Zappy::CommandError("Invalid arguments for PIC command", "EBO");
    }
}