/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Interface
*/

#include "Interface.hpp"

Interface::Interface()
{
    window.create(sf::VideoMode(1920, 1080), "Zappy");
}

Interface::~Interface()
{
    window.close();
}

void Interface::loop()
{
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
}