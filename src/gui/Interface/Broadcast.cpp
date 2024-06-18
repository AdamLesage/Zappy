/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Broadcast
*/

#include "Broadcast.hpp"

Zappy::Broadcast::Broadcast(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<GuiConnect> guiConnect)
{
    _guiConnect = guiConnect;
    _window = window;
    if (!font.loadFromFile("./asset/gui/Farmhouse.otf"))
        throw InterfaceError("Error: font not found", "Interface");
    _broadcasts_textures.push_back(sf::Texture());
    if (_broadcasts_textures[0].loadFromFile("./asset/sprite/broadcast/talk_buble.png") == false)
        throw InterfaceError("Error: broadcast2.png not found", "Interface");
    _broadcasts_textures.push_back(sf::Texture());
    if (_broadcasts_textures[1].loadFromFile("./asset/sprite/broadcast/message.png") == false)
        throw InterfaceError("Error: broadcast.png not found", "Interface");
    _broadcasts_sprites.push_back(sf::Sprite());
    _broadcasts_messages.push_back(sf::Sprite());
    _broadcasts_sprites[0].setTexture(_broadcasts_textures[0]);
    _broadcasts_messages[0].setTexture(_broadcasts_textures[1]);
}

Zappy::Broadcast::~Broadcast()
{
}

void Zappy::Broadcast::display()
{
    if (_clock.getElapsedTime().asSeconds() < 5) {
        _window->draw(_broadcasts_sprites[_broadcasts_sprites.size() - 1]);
        _window->draw(_broadcasts_text[_broadcasts_text.size() - 1]);
    }
}

void Zappy::Broadcast::check_player_broadcast(int i)
{
    if (_guiConnect->_players[i]->getMessage() != "") {
        _broadcasts_text.push_back(sf::Text(_guiConnect->_players[i]->getMessage(), font, 15));
        if (_broadcasts_text.size() > 1) {
            _broadcasts_sprites.push_back(sf::Sprite());
            _broadcasts_sprites[_broadcasts_sprites.size() - 1].setScale(0.35, 0.1);
            _broadcasts_sprites[_broadcasts_sprites.size() - 1].setTexture(_broadcasts_textures[0]);
            _broadcasts_sprites[_broadcasts_sprites.size() - 1].setPosition(_guiConnect->_players[i]->getPosition()[0] * 102.4 + 100, (_guiConnect->_players[i]->getPosition()[1] + 1) * 102.4);
            printf("broadcasts_sprites size: %lu\n", _broadcasts_sprites.size());
        }
        _broadcasts_text[_broadcasts_text.size() - 1].setPosition(_guiConnect->_players[i]->getPosition()[0] * 102.4 + 130, (_guiConnect->_players[i]->getPosition()[1] + 1) * 102.4 + 10);
        _broadcasts_text[_broadcasts_text.size() - 1].setFillColor(sf::Color::Black);
        _guiConnect->_players[i]->setMessage("");
        _clock.restart();
    }
}
