/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AInventory
*/

#include "AInventory.hpp"

int AInventory::get(std::string name)
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

void AInventory::set(std::string name, int value)
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

void AInventory::add(std::string name, int value)
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

void AInventory::remove(std::string name, int value)
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

void AInventory::Empty_all()
{
    _food = 0;
    _linemate = 0;
    _deraumere = 0;
    _sibur = 0;
    _mendiane = 0;
    _phiras = 0;
    _thystame = 0;
}