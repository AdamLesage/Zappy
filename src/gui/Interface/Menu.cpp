/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Menu
*/

#include "Menu.hpp"

Zappy::Menu::Menu(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<PlayerPrint> playerPrint)
{
    this->_window = window;
    this->_playerPrint = playerPrint;
    this->menu = false;
    loading_texture.push_back(sf::Texture());
    loading_texture.push_back(sf::Texture());
    if (loading_texture[0].loadFromFile("./asset/gui/fonddd.jpg") == false)
        throw InterfaceError("Error: fonddd.jpg not found", "Interface");
    if (loading_texture[1].loadFromFile("./asset/gui/fonddd.jpg") == false)
        throw InterfaceError("Error: fonddd.jpg not found", "Interface");
    if (!font.loadFromFile("./asset/gui/Farmhouse.otf"))
        throw InterfaceError("Error: Farmhouse.otf not found", "Interface");
    loading.setSize(sf::Vector2f(1920, 1080));
    loading.setTexture(&loading_texture[0]);
    loadingBar.setSize(sf::Vector2f(1600, 40));
    loadingBar.setFillColor(sf::Color(119 , 181 , 254));
    loadingBar.setPosition(160, 900);
    buttons.push_back(std::make_shared<Button>(sf::Vector2f(200, 50), sf::Vector2f(860, 350), sf::Color::Green, 5, sf::Color::Black));
    buttons.push_back(std::make_shared<Button>(sf::Vector2f(200, 50), sf::Vector2f(860, 450), sf::Color::Green, 5, sf::Color::Black));
    buttons.push_back(std::make_shared<Button>(sf::Vector2f(200, 50), sf::Vector2f(860, 550), sf::Color::Green, 5, sf::Color::Black));
    buttons.push_back(std::make_shared<Button>(sf::Vector2f(200, 50), sf::Vector2f(860, 650), sf::Color::Green, 5, sf::Color::Black));
    buttons[0]->setText("Start");
    buttons[1]->setText("Zappy");
    buttons[2]->setText("Shop");
    buttons[3]->setText("Credits");
    menu = false;
    credit = std::make_shared<Credit>(window);
    shop = std::make_shared<Shop>(window, playerPrint);
    for (int i = 0; i < 8; i++) {
        pplayer_rank_text.push_back(sf::Text("Level " + std::to_string(i + 1), font, 40));
        pplayer_rank_text[i].setFillColor(sf::Color::White);
        pplayer_rank_text[i].setPosition(100, 100 + i * 100);
    }
    loadingText.setFont(font);
    loadingText.setString("Zappy");
    loadingText.setCharacterSize(250);
    loadingText.setFillColor(sf::Color::Cyan);
    loadingText.setPosition(_window->getSize().x / 2 - loadingText.getLocalBounds().width / 2, _window->getSize().y / 2 - loadingText.getLocalBounds().height / 2);
    loadingText.setStyle(sf::Text::Bold);
    loadingText.setOutlineThickness(5);
    loadingText.setOutlineColor(sf::Color::Black);
}

Zappy::Menu::~Menu()
{
}

void Zappy::Menu::display()
{
    loading.setTexture(&loading_texture[0]);
    _window->clear();
    _window->draw(loading);
    _window->display();
    clock.restart();
    while (clock.getElapsedTime().asSeconds() < 5) {
        float progress = clock.getElapsedTime().asSeconds() / 5;
        loadingBar.setSize(sf::Vector2f(1600 * progress, 60));
        _window->clear();
        _window->draw(loading);
        _window->draw(loadingBar);
        _window->draw(loadingText);
        _window->display();
    }
    loading.setTexture(&loading_texture[1]);
    loadingBar.setSize(sf::Vector2f(500, 1080));
    loadingBar.setPosition(0, 0);
    loadingBar.setFillColor(sf::Color(0, 0, 0, 150));
    while (menu == false) {
        _window->clear(sf::Color::Black);
        while (_window->pollEvent(event)) {
            menu = buttons[0]->checkClick(_window, event);
            if (buttons[3]->checkClick(_window, event) == true) {
                credit->start();
                credit->run();
            }
            buttons[1]->checkClick(_window, event);
            if (buttons[2]->checkClick(_window, event) == true) {
                shop->start();
                shop->display();
            }
            if (event.type == sf::Event::Closed)
                _window->close();
        }
        _window->draw(loading);
        _window->draw(loadingBar);
        for (int i = 0; i < 8; i++) {
            _window->draw(_playerPrint->getPlayerRank()[i]);
            _window->draw(pplayer_rank_text[i]);
            if (i < 4)
                buttons[i]->displayButton(_window);
        }
        _window->display();
    }
}