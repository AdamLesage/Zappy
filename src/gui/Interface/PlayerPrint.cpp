/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PlayerPrint
*/

#include "PlayerPrint.hpp"


zappy::PlayerPrint::PlayerPrint(std::shared_ptr<GuiConnect> guiConnect, std::shared_ptr<sf::RenderWindow> window)
{
    this->_window = window;
    this->_guiConnect = guiConnect;
}

zappy::PlayerPrint::~PlayerPrint()
{
}

void zappy::PlayerPrint::display()
{
    return;
}