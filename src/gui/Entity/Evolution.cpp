/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Evolution
*/

#include "Evolution.hpp"

Evolution::Evolution(std::pair<int, int> position, std::pair<int, int> size,
    sf::Clock clock, std::string texture) : _position(position), _size(size), _clock(clock)
{
    _texture.loadFromFile(texture);
}

Evolution::~Evolution()
{
}

std::pair<int, int> Evolution::getPosition() const
{
    return _position;
}

sf::Clock Evolution::getClock() const
{
    return _clock;
}

std::pair<int, int> Evolution::getSize() const
{
    return _size;
}

void Evolution::setPosition(int x, int y)
{
    _position.first = x;
    _position.second = y;
}

void Evolution::setClock(sf::Clock clock)
{
    _clock = clock;
}

void Evolution::setSize(int x, int y)
{
    _size.first = x;
    _size.second = y;
}
