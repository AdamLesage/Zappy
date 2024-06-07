/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PDR
*/

#include "PDR.hpp"

Zappy::PDR::PDR()
{
}

Zappy::PDR::~PDR()
{
}


void Zappy::PDR::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                int timeUnit,
                                bool isRunning
)
{
    (void)size_map;
    (void)tiles;
    (void)eggs;
    (void)timeUnit;
    (void)isRunning;
    if (parsedData.size() < 2)
        return;
    for (auto &player : players) {
        if (player->_playerNumber == std::stoi(parsedData[1])) {
            int ressource = std::stoi(parsedData[2]);
            std::string ressourceName = "";
            if (ressource == 0)
                ressourceName = "Food";
            else if (ressource == 1)
                ressourceName = "Linemate";
            else if (ressource == 2)
                ressourceName = "Deraumere";
            else if (ressource == 3)
                ressourceName = "Sibur";
            else if (ressource == 4)
                ressourceName = "Mendiane";
            else if (ressource == 5)
                ressourceName = "Phiras";
            else if (ressource == 6)
                ressourceName = "Thystame";
            int tileressource = tiles[player->_position[1]][player->_position[0]]->_inventory->get(ressourceName);
            int playerressource = player->_inventory->get(ressourceName);
            tiles[player->_position[1]][player->_position[0]]->_inventory->set(ressourceName, tileressource + playerressource);
            player->_inventory->set(ressourceName, 0);
        }
    }
}