/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Shop
*/

#include "Shop.hpp"

Zappy::Shop::Shop(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<PlayerPrint> playerPrint)
{
    this->_window = window;
    this->_playerPrint = playerPrint;
    loading_texture.push_back(sf::Texture());
    if (loading_texture[0].loadFromFile("./asset/gui/fonddd.jpg") == false)
        throw InterfaceError("Error: fonddd.jpg not found", "Interface");
    if (!font.loadFromFile("./asset/gui/Farmhouse.otf"))
        throw InterfaceError("Error: Farmhouse.otf not found", "Interface");
    loading.setSize(sf::Vector2f(1920, 1080));
    loading.setTexture(&loading_texture[0]);
    for (int i = 0; i < 8; i++) {
        pplayer_rank_text.push_back(sf::Text("Level " + std::to_string(i + 1), font, 40));
        buttons.push_back(std::make_shared<Button>(sf::Vector2f(100, 50), sf::Vector2f(0, 0),sf::Color::White ,  5, sf::Color::Black));
        buttons[i]->setText("Buy");
        pplayer_rank_text[i].setFillColor(sf::Color::White);
        pplayer_rank_text[i].setPosition(100, 100 + i * 100);
    }
    shoprect.setSize(sf::Vector2f(500, 1080));
    shoprect.setPosition(0, 0);
    shoprect.setFillColor(sf::Color(0, 250, 0, 150));
    isRunning = false;
    close = std::make_shared<Button>(sf::Vector2f(50, 50), sf::Vector2f(20, 20), sf::Color::White);
    closeTexture.loadFromFile("./asset/sprite/close.png");
    closeSprite.setTexture(closeTexture);
    close->setSprite(closeSprite);
}

Zappy::Shop::~Shop()
{
}

void Zappy::Shop::display()
{
    while (isRunning) {
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                isRunning = false;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    isRunning = false;
                }
            }
            if (close->checkClick(_window, event) == true)
                isRunning = false;
        }
        _window->clear(sf::Color::Black);
        _window->draw(loading);
        _window->draw(shoprect);
        for (int i = 0; i < 8; i++) {
            buttons[i]->setPosition(sf::Vector2f(300, 100 + i * 100));
            buttons[i]->displayButton(_window);
            buttons[i]->checkClick(_window, event);
            _window->draw(pplayer_rank_text[i]);
            _window->draw(_playerPrint->getPlayerRank()[i]);
        }
        close->displayButton(_window);
        _window->display();
    }
}