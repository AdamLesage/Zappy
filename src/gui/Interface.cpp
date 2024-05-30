/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Interface
*/

#include "Interface.hpp"

Interface::Interface()
{
    window = std::make_shared<sf::RenderWindow>();
    window->create(sf::VideoMode(1920, 1080), "Zappy");
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(10, 25), sf::Vector2f(100, 20), sf::Vector2f(100, 100), sf::Color(150, 150, 150), 4, sf::Color::Black));
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(10, 25), sf::Vector2f(100, 20), sf::Vector2f(100, 200), sf::Color(150, 150, 150), 4, sf::Color::Black));
}

Interface::~Interface()
{
    window->close();
}

void Interface::loop()
{
    while (window->isOpen()) {
        window->clear(sf::Color::White);
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        for (auto &bar : bars) {
            bar->checkClick(window);
            bar->displayBar(window);
        }
        window->display();
    }
}