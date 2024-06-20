/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Player
*/

#include "Player.hpp"

Zappy::Player::Player()
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
    _travelled = 0;
}

Zappy::Player::~Player()
{
}
