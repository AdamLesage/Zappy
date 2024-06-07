/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIN
*/

#include "PIN.hpp"

Zappy::PIN::PIN()
{
}

Zappy::PIN::~PIN()
{
}

void Zappy::PIN::askCommand(int socket, std::vector<std::string> args)
{
    std::string command = "pin " + args[0] + "\n";
    write(socket, command.c_str(), command.length());
}

void Zappy::PIN::applyChanges(std::vector<std::string> parsedData,
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
    (void)timeUnit;
    (void)isRunning;
    (void)eggs;
    (void)tiles;


    for (auto &player : players) {
        if (player->getPlayerNumber() == std::stoi(parsedData[1])) {
            player->setInventory(std::make_shared<Inventory>());
            player->_inventory->set("Food",std::stoi(parsedData[4]));
            player->_inventory->set("Linemate",std::stoi(parsedData[5]));
            player->_inventory->set("Deraumere",std::stoi(parsedData[6]));
            player->_inventory->set("Sibur",std::stoi(parsedData[7]));
            player->_inventory->set("Mendiane",std::stoi(parsedData[8]));
            player->_inventory->set("Phiras",std::stoi(parsedData[9]));
            player->_inventory->set("Thystame",std::stoi(parsedData[10]));
            break;
        }
    }
}