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
    _broadcasts_messages.push_back(sf::Sprite());
    _broadcasts_messages[0].setTexture(_broadcasts_textures[1]);
}

Zappy::Broadcast::~Broadcast()
{
}

void Zappy::Broadcast::display(std::shared_ptr<Player> player)
{
    for (size_t index = 0; index != _broadcasts.size(); index++) {
        if (player->getPlayerNumber() == _broadcasts[index].first) {
            if (_clock[index].getElapsedTime().asSeconds() >= 2) {
                _broadcasts.erase(_broadcasts.begin() + index);
                _clock.erase(_clock.begin() + index);
            } else {
                _broadcasts[index].second.setPosition(player->getPosition()[0] * 102.4 + 100, (player->getPosition()[1] + 1) * 102.4);
                _window->draw(_broadcasts[index].second);
            }
            return;
        }
    }
}

void Zappy::Broadcast::check_player_broadcast(std::shared_ptr<Player> player)
{
    if (player->getMessage() != "") {
        _broadcasts.push_back(std::make_pair(0, sf::Sprite()));
        _broadcasts[_broadcasts.size() - 1].first = player->getPlayerNumber();
        _broadcasts[_broadcasts.size() - 1].second.setScale(0.1, 0.1);
        _broadcasts[_broadcasts.size() - 1].second.setTexture(_broadcasts_textures[0]);
        _broadcasts[_broadcasts.size() - 1].second.setPosition(player->getPosition()[0] * 102.4 + 100, (player->getPosition()[1] + 1) * 102.4);
        player->setMessage("");
        _clock.push_back(sf::Clock());
    }
}
