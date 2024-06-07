/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** BCT
*/

#include "BCT.hpp"
#include "../../Entity/Tile.hpp"

Zappy::BCT::BCT()
{
}

Zappy::BCT::~BCT()
{
}

void Zappy::BCT::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 1)
        throw Zappy::CommandError("Invalid number of arguments for SGT command", "BCT");
    std::string message = "bct " + args[1] + " " + args[2] + "\n";
    write(fd, message.c_str(), message.size());
}

void Zappy::BCT::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                int timeUnit,
                                bool isRunning
)
{
    (void)size_map; // unused
    (void)players; // unused
    (void)eggs; // unused
    (void)timeUnit; // unused
    (void)isRunning; // unused
    if (parsedData.size() != 10)
        throw std::invalid_argument("Invalid number of arguments for SGT command");
    if (tiles.size() == 0)
        return;
    int x = std::stoi(parsedData[1]);
    int y = std::stoi(parsedData[2]);
    tiles[y][x]->_inventory->_food = std::stoi(parsedData[3]);
    tiles[y][x]->_inventory->set("Linemate", std::stoi(parsedData[4]));
    tiles[y][x]->_inventory->set("Deraumere", std::stoi(parsedData[5]));
    tiles[y][x]->_inventory->set("Sibur", std::stoi(parsedData[6]));
    tiles[y][x]->_inventory->set("Mendiane", std::stoi(parsedData[7]));
    tiles[y][x]->_inventory->set("Phiras", std::stoi(parsedData[8]));
    tiles[y][x]->_inventory->set("Thystame", std::stoi(parsedData[9]));
}
