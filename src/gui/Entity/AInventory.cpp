/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AInventory
*/

#include "AInventory.hpp"

int Zappy::AInventory::get(std::string name)
{
    if (name == "Food")
        return _food;
    if (name == "Linemate")
        return _linemate;
    if (name == "Deraumere")
        return _deraumere;
    if (name == "Sibur")
        return _sibur;
    if (name == "Mendiane")
        return _mendiane;
    if (name == "Phiras")
        return _phiras;
    if (name == "Thystame")
        return _thystame;
    return 0;

}

void Zappy::AInventory::set(std::string name, int value)
{
    if (name == "Food")
        _food = value;
    if (name == "Linemate")
        _linemate = value;
    if (name == "Deraumere")
        _deraumere = value;
    if (name == "Sibur")
        _sibur = value;
    if (name == "Mendiane")
        _mendiane = value;
    if (name == "Phiras")
        _phiras = value;
    if (name == "Thystame")
        _thystame = value;
}

void Zappy::AInventory::add(std::string name, int value)
{
    if (name == "Food")
        _food += value;
    if (name == "Linemate")
        _linemate += value;
    if (name == "Deraumere")
        _deraumere += value;
    if (name == "Sibur")
        _sibur += value;
    if (name == "Mendiane")
        _mendiane += value;
    if (name == "Phiras")
        _phiras += value;
    if (name == "Thystame")
        _thystame += value;
}

void Zappy::AInventory::remove(std::string name, int value)
{
    if (name == "Food")
        _food -= value;
    if (name == "Linemate")
        _linemate -= value;
    if (name == "Deraumere")
        _deraumere -= value;
    if (name == "Sibur")
        _sibur -= value;
    if (name == "Mendiane")
        _mendiane -= value;
    if (name == "Phiras")
        _phiras -= value;
    if (name == "Thystame")
        _thystame -= value;
}

void Zappy::AInventory::Empty_all()
{
    _food = 0;
    _linemate = 0;
    _deraumere = 0;
    _sibur = 0;
    _mendiane = 0;
    _phiras = 0;
    _thystame = 0;
}

void Zappy::AInventory::setpos(int x, int y)
{
    this->_x = x;
    this->_y = y;
}