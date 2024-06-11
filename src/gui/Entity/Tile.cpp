/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Tile
*/

#include "Tile.hpp"

Zappy::Tile::Tile()
{
}

Zappy::Tile::Tile(sf::Vector2f position, std::shared_ptr<Inventory> inventory)
{
    _position = position;
    _inventory = inventory;
}

Zappy::Tile::~Tile()
{
}

sf::Vector2f Zappy::Tile::getPosition() const
{
    return _position;
}
