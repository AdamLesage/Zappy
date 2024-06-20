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
                return tile;
            }
        }
    }
    throw Zappy::ConnectError("Tile not found", "GuiConnect::getTileByCoords");
    return nullptr;
}

int GuiConnect::getEggNbOnTile(std::pair<int, int> coords)
{
    int nb = 0;

    for (const auto &row : _tiles)
    {
        for (const auto &tile : row)
        {
            int x = tile->_position.x;
            int y = tile->_position.y;
            if (x == coords.first && y == coords.second)
            {
                for (const auto &egg : this->_eggs)
                {
                    std::array<int, 2> egg_coords = egg->getPosition();
                    if (egg_coords[0] == x && egg_coords[1] == y)
                    {
                        nb++;
                    }
                }
            }
        }
        return nb;
    }
}

int GuiConnect::getPlayerNbOnTile(std::pair<int, int> coords)
{
    int nb = 0;

    for (const auto &row : _tiles)
    {
        for (const auto &tile : row)
        {
            int x = tile->_position.x;
            int y = tile->_position.y;
            if (x == coords.first && y == coords.second)
            {
                for (const auto &player : this->_players)
                {
                    std::array<int, 2> player_coords = player->getPosition();
                    if (player_coords[0] == x && player_coords[1] == y)
                    {
                        nb++;
                    }
                }
            }
        }
        return nb;
    }
}