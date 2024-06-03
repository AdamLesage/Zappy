/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Tile
*/

#include "Tile.hpp"

Tile::Tile()
{
}

Tile::Tile(sf::Vector2f position, std::shared_ptr<Inventory> inventory)
{
    _position = position;
    _inventory = inventory;
}

Tile::~Tile()
{
}
