/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AInventory
*/

#include "AInventory.hpp"

int AInventory::get(std::string name)
{
    if (name == "food")
        return _food;
    if (name == "linemate")
        return _linemate;
    if (name == "deraumere")
        return _deraumere;
    if (name == "sibur")
        return _sibur;
    if (name == "mendiane")
        return _mendiane;
    if (name == "phiras")
        return _phiras;
    if (name == "thystame")
        return _thystame;
    return 0;

}

void AInventory::set(std::string name, int value)
{
    if (name == "food")
        _food = value;
    if (name == "linemate")
        _linemate = value;
    if (name == "deraumere")
        _deraumere = value;
    if (name == "sibur")
        _sibur = value;
    if (name == "mendiane")
        _mendiane = value;
    if (name == "phiras")
        _phiras = value;
    if (name == "thystame")
        _thystame = value;
}

void AInventory::add(std::string name, int value)
{
    if (name == "food")
        _food += value;
    if (name == "linemate")
        _linemate += value;
    if (name == "deraumere")
        _deraumere += value;
    if (name == "sibur")
        _sibur += value;
    if (name == "mendiane")
        _mendiane += value;
    if (name == "phiras")
        _phiras += value;
    if (name == "thystame")
        _thystame += value;
}

void AInventory::remove(std::string name, int value)
{
    if (name == "food")
        _food -= value;
    if (name == "linemate")
        _linemate -= value;
    if (name == "deraumere")
        _deraumere -= value;
    if (name == "sibur")
        _sibur -= value;
    if (name == "mendiane")
        _mendiane -= value;
    if (name == "phiras")
        _phiras -= value;
    if (name == "thystame")
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