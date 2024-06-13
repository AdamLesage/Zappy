/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Egg
*/

#include "Egg.hpp"

Zappy::Egg::Egg()
{
    _teamName = "";
    _playerName = "";
    _level = 0;
    _position[0] = 0;
    _position[1] = 0;
    _playerNumber = 0;
    _inventory = nullptr;
    _isIncanting = false;
    _orientation = 0;
    _message = "";
    _eggNb = 0;
}

Zappy::Egg::~Egg()
{
}
