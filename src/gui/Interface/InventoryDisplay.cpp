/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** InventoryDisplay
*/

#include "InventoryDisplay.hpp"

Zappy::InventoryDisplay::InventoryDisplay(std::shared_ptr<GuiConnect> guiConnect, std::shared_ptr<sf::RenderWindow> window)
{
    this->_window = window;
    this->_guiConnect = guiConnect;
    this->current_player_index = -1;

    if (font.loadFromFile("./asset/gui/Farmhouse.otf") == false)
        throw InterfaceError("Error: Farmhouse.otf not found", "Interface");
    for (int i = 0; i != 12; i++) {
        this->playerInfo.push_back(sf::Text("", font, 45));
        this->playerInfo[i].setFillColor(sf::Color::Black);
    }
    for (int i = 0; i < 7; i++)
        ressource_texture.push_back(sf::Texture());
    if (ressource_texture[0].loadFromFile("./asset/sprite/ressource/wheat.png") == false)
        throw InterfaceError("Error: wheat.png not found", "Interface");
    if (ressource_texture[1].loadFromFile("./asset/sprite/ressource/bacon.png") == false)
        throw InterfaceError("Error: bacon.png not found", "Interface");
    if (ressource_texture[2].loadFromFile("./asset/sprite/ressource/egg.png") == false)
        throw InterfaceError("Error: egg.png not found", "Interface");
    if (ressource_texture[3].loadFromFile("./asset/sprite/ressource/milk.png") == false)
        throw InterfaceError("Error: milk.png not found", "Interface");
    if (ressource_texture[4].loadFromFile("./asset/sprite/ressource/horseshoes.png") == false)
        throw InterfaceError("Error: horseshoes.png not found", "Interface");
    if (ressource_texture[5].loadFromFile("./asset/sprite/ressource/rabbit_hide.png") == false)
        throw InterfaceError("Error: rabbit_hide.png not found", "Interface");
    if (ressource_texture[6].loadFromFile("./asset/sprite/ressource/wool.png") == false)
        throw InterfaceError("Error: wool.png not found", "Interface");

    for (int i = 0; i < 7; i++) {
        _ressource_sprite.push_back(sf::RectangleShape());
        _ressource_sprite[i].setFillColor(sf::Color::White);
        _ressource_sprite[i].setSize(sf::Vector2f(35, 35));
        _ressource_sprite[i].setTexture(&ressource_texture[i]);
    }

    playerInfo[0].setCharacterSize(30);
    playerInfo[0].setPosition(window->getSize().x - 180, window->getSize().y / 2 + 30);
    playerInfo[1].setCharacterSize(30);
    playerInfo[1].setPosition(window->getSize().x - 180, window->getSize().y / 2 + 60);
    playerInfo[2].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 150);
    _ressource_sprite[0].setPosition(window->getSize().x - 290, window->getSize().y / 2 + 155);
    playerInfo[3].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 200);
    _ressource_sprite[1].setPosition(window->getSize().x - 290, window->getSize().y / 2 + 205);
    playerInfo[4].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 250);
    _ressource_sprite[2].setPosition(window->getSize().x - 290, window->getSize().y / 2 + 255);
    playerInfo[5].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 300);
    _ressource_sprite[3].setPosition(window->getSize().x - 290, window->getSize().y / 2 + 305);
    playerInfo[6].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 350);
    _ressource_sprite[4].setPosition(window->getSize().x - 290, window->getSize().y / 2 + 355);
    playerInfo[7].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 400);
    _ressource_sprite[5].setPosition(window->getSize().x - 290, window->getSize().y / 2 + 405);
    playerInfo[8].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 450);
    _ressource_sprite[6].setPosition(window->getSize().x - 290, window->getSize().y / 2 + 455);
    playerInfo[9].setCharacterSize(20);
    playerInfo[9].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 100);
    playerInfo[10].setCharacterSize(20);
    playerInfo[10].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 130);
    // playerInfo[11].setCharacterSize(30);
    // playerInfo[11].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 130);


    this->back.setPosition(window->getSize().x - 300, window->getSize().y / 2);
    this->back.setSize(sf::Vector2f(300, window->getSize().y / 2));
    this->back.setFillColor(sf::Color(255,215,0));
    this->back.setOutlineThickness(2);
    this->back.setOutlineColor(sf::Color::Black);

    this->header.setPosition(window->getSize().x - 300, window->getSize().y / 2);
    this->header.setSize(sf::Vector2f(300, 100));
    this->header.setFillColor(sf::Color(200,150,0));
    this->header.setOutlineThickness(2);
    this->header.setOutlineColor(sf::Color::Black);

    this->closeButton.reset(new Button(sf::Vector2f(50, 50), sf::Vector2f(window->getSize().x - 55, window->getSize().y / 2), sf::Color::White));

    sf::Texture closeTexture;
    if (closeTexture.loadFromFile("./asset/sprite/close.png")) {
        this->closeButton->setSprite(sf::Sprite(closeTexture));
    }
    this->SkinPlayer.setFillColor(sf::Color::White);
    this->SkinPlayer.setPosition(sf::Vector2f(window->getSize().x - 300, window->getSize().y / 2));
    this->SkinPlayer.setSize(sf::Vector2f(100, 100));
}

Zappy::InventoryDisplay::~InventoryDisplay()
{
}

void Zappy::InventoryDisplay::check_event(sf::Event *event, std::vector<sf::Sprite> players_sprites, sf::View view)
{
    if (closeButton->checkClick(_window)) {
        current_player_index = -1;
    }
    if (event->type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mouse = _window->mapPixelToCoords(sf::Vector2i(event->mouseButton.x, event->mouseButton.y), view);
        for (size_t i = 0; i != this->_guiConnect->_players.size(); i++) {
            if (players_sprites[i].getGlobalBounds().contains(mouse)) {
                current_player_index = i;
                playerInfo[0].setString("Lvl: " + std::to_string(_guiConnect->_players[i]->getLevel()));
                playerInfo[1].setString("Team: " + _guiConnect->_players[i]->getTeamName());
                playerInfo[2].setString("Food " + std::to_string(_guiConnect->_players[i]->getInventory()->_food));
                playerInfo[3].setString("Linemate " + std::to_string(_guiConnect->_players[i]->getInventory()->_linemate));
                playerInfo[4].setString("Deraumere " + std::to_string(_guiConnect->_players[i]->getInventory()->_deraumere));
                playerInfo[5].setString("Sibur " + std::to_string(_guiConnect->_players[i]->getInventory()->_sibur));
                playerInfo[6].setString("Mendiane " + std::to_string(_guiConnect->_players[i]->getInventory()->_mendiane));
                playerInfo[7].setString("Phiras " + std::to_string(_guiConnect->_players[i]->getInventory()->_phiras));
                playerInfo[8].setString("Thystame " + std::to_string(_guiConnect->_players[i]->getInventory()->_thystame));
                playerInfo[9].setString("Player " + std::to_string(_guiConnect->_players[i]->getPlayerNumber()));
                playerInfo[10].setString("Orientation " + std::to_string(_guiConnect->_players[i]->getOrientation()));
                playerInfo[11].setString("Travelled " + std::to_string(_guiConnect->_players[i]->getTravelled()));
                this->SkinPlayer.setTexture(players_sprites[i].getTexture());
                this->SkinPlayer.setTextureRect(players_sprites[i].getTextureRect());
            }
        }
    }
}

void Zappy::InventoryDisplay::display()
{
    if (current_player_index != -1) {
        this->_window->draw(this->back);
        this->_window->draw(this->header);
        for (int i = 0; i != 12; i++) {
            this->_window->draw(this->playerInfo[i]);
        }
        for (int i = 0; i < 7; i++) {
            this->_window->draw(this->_ressource_sprite[i]);
        }
        this->_window->draw(this->SkinPlayer);
        this->closeButton->displayButton(this->_window);
    }
}
