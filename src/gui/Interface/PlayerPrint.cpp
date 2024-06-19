/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PlayerPrint
*/

#include "PlayerPrint.hpp"


Zappy::PlayerPrint::PlayerPrint(std::shared_ptr<GuiConnect> guiConnect, std::shared_ptr<sf::RenderWindow> window)
{
    this->_window = window;
    this->_guiConnect = guiConnect;
}

Zappy::PlayerPrint::~PlayerPrint()
{
}

void Zappy::PlayerPrint::display()
{
    return;
}