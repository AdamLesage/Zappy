/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Credit
*/

#include "Credit.hpp"

Zappy::Credit::Credit(std::shared_ptr<sf::RenderWindow> window)
{
    _window = window;
    isRunning = true;
    font.loadFromFile("./asset/gui/Farmhouse.otf");
    for (int i = 0; i < 7; i++) {
        texts.push_back(sf::Text());
        texts[i].setFont(font);
        texts[i].setCharacterSize(50);
        texts[i].setFillColor(sf::Color::White);
        texts[i].setPosition(850, 100 + i * 100);
    }
    texts[0].setString("This game was made by:");
    texts[1].setString("Adam Lesage");
    texts[2].setString("Mathieu Mazeau");
    texts[3].setString("Nicolas Bertrand");
    texts[4].setString("Romain Chevallier");
    texts[5].setString("Toavina Andriamanampisoa");
    texts[6].setString("Victor Hristea");
}

Zappy::Credit::~Credit()
{
}

void Zappy::Credit::run()
{
    while (isRunning) {
        sf::Event event;
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                isRunning = false;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    isRunning = false;
                }
            }
        }
        _window->clear(sf::Color::Black);
        for (int i = 0; i < 7; i++) {
            _window->draw(texts[i]);
        }
        _window->display();
    }
}