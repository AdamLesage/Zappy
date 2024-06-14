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
    for (int i = 0; i != 9; i++) {
        this->playerInfo.push_back(sf::Text("", font, 45));
        this->playerInfo[i].setFillColor(sf::Color::Black);
    }
    playerInfo[0].setCharacterSize(60);
    playerInfo[0].setPosition(window->getSize().x - 290, window->getSize().y / 2);
    playerInfo[1].setPosition(window->getSize().x - 280, window->getSize().y / 2 + 70);
    playerInfo[2].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 150);
    playerInfo[3].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 200);
    playerInfo[4].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 250);
    playerInfo[5].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 300);
    playerInfo[6].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 350);
    playerInfo[7].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 400);
    playerInfo[8].setPosition(window->getSize().x - 250, window->getSize().y / 2 + 450);

    this->back.setPosition(window->getSize().x - 300, window->getSize().y / 2);
    this->back.setSize(sf::Vector2f(300, window->getSize().y / 2));
    this->back.setFillColor(sf::Color(255,215,0));
    this->back.setOutlineThickness(2);
    this->back.setOutlineColor(sf::Color::Black);
}

Zappy::InventoryDisplay::~InventoryDisplay()
{
}

void Zappy::InventoryDisplay::check_event(sf::Event *event, std::vector<sf::Sprite> players_sprites, sf::View view)
{
    if (event->type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mouse = _window->mapPixelToCoords(sf::Vector2i(event->mouseButton.x, event->mouseButton.y), view);
        for (size_t i = 0; i != this->_guiConnect->_players.size(); i++) {
            if (players_sprites[i].getGlobalBounds().contains(mouse)) {
                current_player_index = i;
                playerInfo[0].setString("Level " + std::to_string(_guiConnect->_players[i]->getLevel()));
                playerInfo[1].setString("Team " + _guiConnect->_players[i]->getTeamName());
                playerInfo[2].setString("Food " + std::to_string(_guiConnect->_players[i]->getInventory()->_food));
                playerInfo[3].setString("Linemate " + std::to_string(_guiConnect->_players[i]->getInventory()->_linemate));
                playerInfo[4].setString("Deraumere " + std::to_string(_guiConnect->_players[i]->getInventory()->_deraumere));
                playerInfo[5].setString("Sibur " + std::to_string(_guiConnect->_players[i]->getInventory()->_sibur));
                playerInfo[6].setString("Mendiane " + std::to_string(_guiConnect->_players[i]->getInventory()->_mendiane));
                playerInfo[7].setString("Phiras " + std::to_string(_guiConnect->_players[i]->getInventory()->_phiras));
                playerInfo[8].setString("Thystame " + std::to_string(_guiConnect->_players[i]->getInventory()->_thystame));
            }
        }
    }
}

void Zappy::InventoryDisplay::display()
{
    if (current_player_index != -1) {
        this->_window->draw(this->back);
        for (int i = 0; i != 9; i++) {
            this->_window->draw(this->playerInfo[i]);
        }
    }
}
