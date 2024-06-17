/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** InfoDisplay
*/

#include "InfoDisplay.hpp"

Zappy::InfoDisplay::InfoDisplay(std::shared_ptr<GuiConnect> guiConnect, std::shared_ptr<sf::RenderWindow> window, std::vector<sf::Sprite> ressource_sprite_)
{
    this->_window = window;
    this->_guiConnect = guiConnect;
    info_ = false;
    font.loadFromFile("./asset/gui/Farmhouse.otf");
    for (int i = 0; i < 20; i++) {
        info.push_back(sf::Text("", font, 45));
        info[i].setFillColor(sf::Color::Black);
    }
    for (int i = 0; i < 7; i++) {
        info_sprites.push_back(sf::Sprite());
    }
    for (int i = 0; i < 7; i++)
        ressource_texture.push_back(sf::Texture());
    if (ressource_texture[0].loadFromFile("./asset/sprite/ressource/bacon.png") == false)
        throw InterfaceError("Error: bacon.png not found", "Interface");
    if (ressource_texture[1].loadFromFile("./asset/sprite/ressource/egg.png") == false)
        throw InterfaceError("Error: egg.png not found", "Interface");
    if (ressource_texture[2].loadFromFile("./asset/sprite/ressource/milk.png") == false)
        throw InterfaceError("Error: milk.png not found", "Interface");
    if (ressource_texture[3].loadFromFile("./asset/sprite/ressource/horseshoes.png") == false)
        throw InterfaceError("Error: horseshoes.png not found", "Interface");
    if (ressource_texture[4].loadFromFile("./asset/sprite/ressource/rabbit_hide.png") == false)
        throw InterfaceError("Error: rabbit_hide.png not found", "Interface");
    if (ressource_texture[5].loadFromFile("./asset/sprite/ressource/wool.png") == false)
        throw InterfaceError("Error: wool.png not found", "Interface");
    if (ressource_texture[6].loadFromFile("./asset/sprite/ressource/wheat.png") == false)
        throw InterfaceError("Error: wheat.png not found", "Interface");
    for (int i = 0; i < 7; i++) {
        info_sprites[i].setTexture(ressource_texture[i]);
        info_sprites[i].setScale(ressource_sprite_[i].getScale().x * 3, ressource_sprite_[i].getScale().y * 3);
    }
}

Zappy::InfoDisplay::~InfoDisplay()
{
}

void Zappy::InfoDisplay::Checkclick(sf::Vector2f mousePos)
{
    for (int i = 0; i < _guiConnect->get_size_map()[0]; i++) {
        for (int j = 0; j < _guiConnect->get_size_map()[1]; j++) {
            sf::FloatRect tileBounds(100 + (i * 102.4), 150 + (j * 102.4), 102.4, 102.4);
            if (tileBounds.contains(mousePos)) {
                info[0].setString("Tile: x " + std::to_string(i + 1) + " y " + std::to_string(j + 1));
                info[1].setString("Player: " + std::to_string(_guiConnect->_tiles[i][j]->_players.size()));
                info[2].setString("Food: " + std::to_string(_guiConnect->_tiles[i][j]->_inventory->get("Food")));
                info[3].setString("Linemate: " + std::to_string(_guiConnect->_tiles[i][j]->_inventory->get("Linemate")));
                info[4].setString("Deraumere: " + std::to_string(_guiConnect->_tiles[i][j]->_inventory->get("Deraumere")));
                info[5].setString("Sibur: " + std::to_string(_guiConnect->_tiles[i][j]->_inventory->get("Sibur")));
                info[6].setString("Mendiane: " + std::to_string(_guiConnect->_tiles[i][j]->_inventory->get("Mendiane")));
                info[7].setString("Phiras: " + std::to_string(_guiConnect->_tiles[i][j]->_inventory->get("Phiras")));
                info[8].setString("Thystame: " + std::to_string(_guiConnect->_tiles[i][j]->_inventory->get("Thystame")));

                float baseY = 1080 - 220;
                float offsetY = 50;
                info[0].setPosition(230, baseY);
                info[1].setPosition(230, baseY + offsetY);
                info[2].setPosition(230, baseY + 2 * offsetY);
                info_sprites[0].setPosition(1130, baseY);
                info[3].setPosition(1230, baseY);
                info_sprites[1].setPosition(1130, baseY + offsetY);
                info[4].setPosition(1230, baseY + offsetY);
                info_sprites[2].setPosition(1130, baseY + 2 * offsetY);
                info[5].setPosition(1230, baseY + 2 * offsetY);
                info_sprites[3].setPosition(630, baseY);
                info[6].setPosition(730, baseY);
                info_sprites[4].setPosition(630, baseY + offsetY);
                info[7].setPosition(730, baseY + offsetY);
                info_sprites[5].setPosition(630, baseY + 2 * offsetY);
                info[8].setPosition(730, baseY + 2 * offsetY);
                info_ = true;
            }
        }
    }
}

void Zappy::InfoDisplay::display()
{
    if (info_) {
        for (int k = 0; k < 9; k++)
            _window->draw(info[k]);
        for (int k = 0; k < 6; k++)
            _window->draw(info_sprites[k]);
    }
}