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
    for (int i = 0; i < 8; i++)
        skinsTexture.push_back(sf::Texture());
    if (skinsTexture[0].loadFromFile("./asset/sprite/shop/rank1shop.png") == false)
        throw InterfaceError("Error: rank1 not found", "Shop");
    if (skinsTexture[1].loadFromFile("./asset/sprite/shop/rank1shopb.png") == false)
        throw InterfaceError("Error: rank1 not found", "Shop");
    if (skinsTexture[2].loadFromFile("./asset/sprite/shop/rank2shop.png") == false)
        throw InterfaceError("Error: rank2 not found", "Shop");
    if (skinsTexture[3].loadFromFile("./asset/sprite/shop/rank2shopb.png") == false)
        throw InterfaceError("Error: rank2 not found", "Shop");
    if (skinsTexture[4].loadFromFile("./asset/sprite/shop/rank3shop.png") == false)
        throw InterfaceError("Error: rank3 not found", "Shop");
    if (skinsTexture[5].loadFromFile("./asset/sprite/shop/rank3shopb.png") == false)
        throw InterfaceError("Error: rank3 not found", "Shop");
    if (skinsTexture[6].loadFromFile("./asset/sprite/shop/rank4shop.png") == false)
        throw InterfaceError("Error: rank4 not found", "Shop");
    if (skinsTexture[7].loadFromFile("./asset/sprite/shop/rank4shopb.png") == false)
        throw InterfaceError("Error: rank4 not found", "Shop");
    if (skinsTexture[8].loadFromFile("./asset/sprite/shop/rank5shop.png") == false)
        throw InterfaceError("Error: rank5 not found", "Shop");
    if (skinsTexture[9].loadFromFile("./asset/sprite/shop/rank5shopb.png") == false)
        throw InterfaceError("Error: rank5 not found", "Shop");
    if (skinsTexture[10].loadFromFile("./asset/sprite/shop/rank6shop.png") == false)
        throw InterfaceError("Error: rank6 not found", "Shop");
    if (skinsTexture[11].loadFromFile("./asset/sprite/shop/rank6shopb.png") == false)
        throw InterfaceError("Error: rank6 not found", "Shop");
    std::size_t j = 0;
    for (std::size_t i = 0; i < skinsTexture.size(); i++) {
        skinsSprite.push_back(sf::Sprite());
        skinsSprite[i].setTexture(skinsTexture[i]);
        skinsSprite[i].setScale(3, 3);
        if (i == 6 || i == 7)
            skinsSprite[i].setScale(2, 2);
        if (i % 2 == 0) {
            skinsSprite[i].setTextureRect(_playerPrint->getPlayerOrientation()[i - j][2]);
            skinsSprite[i].setPosition(665, 400);
            printf("i: %ld\n", i);
        } else {
            skinsSprite[i].setPosition(1305, 400);
            j++;
            skinsSprite[i].setTextureRect(_playerPrint->getPlayerOrientation()[i - j][2]);
            printf("i: %ld\n", i - j);
        }
    }
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
    buyButtons.push_back(std::make_shared<Button>(sf::Vector2f(100, 50), sf::Vector2f(640, 540), sf::Color::Red, 5, sf::Color::Black));
    buyButtons[0]->setText("Buy");
    buyButtons.push_back(std::make_shared<Button>(sf::Vector2f(100, 50), sf::Vector2f(1280, 540), sf::Color::Blue, 5, sf::Color::Black));
    buyButtons[1]->setText("Buy");
}

Zappy::Shop::~Shop()
{
}

void Zappy::Shop::display_skin(int skin)
{
    bool Running = true;
    int skinreal = skin;
    for (int i = 0; i < skin; i++)
        skinreal++;
    while (Running) {
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Running = false;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    Running = false;
                }
            }
            if (close->checkClick(_window, event) == true)
                isRunning = false;
        }
        _window->clear(sf::Color::Black);
        _window->draw(loading);
        _window->draw(shoprect);
        for (int i = 0; i < 8; i++) {
            _window->draw(pplayer_rank_text[i]);
            _window->draw(_playerPrint->getPlayerRank()[i]);
        }
        buyButtons[0]->checkClick(_window, event);
        buyButtons[1]->checkClick(_window, event);
        buyButtons[0]->displayButton(_window);
        buyButtons[1]->displayButton(_window);
        close->displayButton(_window);
        _window->draw(skinsSprite[skinreal]);
        _window->draw(skinsSprite[skinreal + 1]);
        printf("skin: %d\n", skinreal);
        _window->display();
    }
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
            if (buttons[i]->checkClick(_window, event) == true)
                display_skin(i);
            _window->draw(pplayer_rank_text[i]);
            _window->draw(_playerPrint->getPlayerRank()[i]);
        }
        close->displayButton(_window);
        _window->display();
    }
}