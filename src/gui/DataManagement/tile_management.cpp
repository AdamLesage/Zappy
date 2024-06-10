/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tile_management
*/

#include "../ServerInfo/GuiConnect.hpp"
#include "../ServerInfo/ConnectError.hpp"

Zappy::Inventory GuiConnect::update_inventory(std::vector<std::string> args, Zappy::Inventory tmp)
{
    tmp.set("Food", std::stoi(args[3]));
    tmp.set("Linemate", std::stoi(args[4]));
    tmp.set("Deraumere", std::stoi(args[5]));
    tmp.set("Sibur", std::stoi(args[6]));
    tmp.set("Mendiane", std::stoi(args[7]));
    tmp.set("Phiras", std::stoi(args[8]));
    tmp.set("Thystame", std::stoi(args[9]));
    return tmp;
}

std::shared_ptr<Zappy::Tile> GuiConnect::getTileByCoords(std::pair<int, int> coords)
{
    for (const auto &row : _tiles)
    {
        for (const auto &tile : row)
        {
            int x = tile->_position.x;
            int y = tile->_position.y;
            if (x == coords.first && y == coords.second)
            {
                printf("tile found x = %d, y = %d\n", x , y);
                return tile;
            }
        }
    }
    printf("tile not found\n");
    throw Zappy::ConnectError("Tile not found", "GuiConnect::getTileByCoords");
    return nullptr;
}
