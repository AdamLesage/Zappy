/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PGT
*/

#include "PGT.hpp"

Zappy::PGT::PGT()
{
}

Zappy::PGT::~PGT()
{
}


void Zappy::PGT::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                std::vector<std::string> &teams,
                                int &timeUnit,
                                bool &isRunning
)
{
    (void)size_map;
    (void)tiles;
    (void)eggs;
    (void)timeUnit;
    (void)isRunning;
    (void)teams;
    
    if (parsedData.size() != 3)
        throw Zappy::CommandError("PGT command has not the right number of arguments", "PGT");
    try {
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
                else
                    throw Zappy::CommandError("PGT command has invalid arguments", "PGT");
                int tileressource = tiles[player->_position[0]][player->_position[1]]->_inventory->get(ressourceName);
                int playerressource = player->_inventory->get(ressourceName);
                player->_inventory->set(ressourceName, playerressource + tileressource);
                tiles[player->_position[0]][player->_position[1]]->_inventory->set(ressourceName, 0);
            }
        }
    } catch (std::exception &e) {
        throw Zappy::CommandError("PGT command has invalid arguments", "PGT");
    }
}