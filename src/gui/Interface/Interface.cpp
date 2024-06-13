/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Interface
*/

#include <unistd.h>
#include "Interface.hpp"

Zappy::Interface::Interface()
{
    info_ = false;
    sound_volume = 50;
    window = std::make_shared<sf::RenderWindow>();
    window->create(sf::VideoMode(1920, 1080), "Zappy");
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(20, 50), sf::Vector2f(200, 40), sf::Vector2f(1700, 125), sf::Color(150, 150, 150), 5, sf::Color::Black));
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(20, 50), sf::Vector2f(200, 40), sf::Vector2f(1700, 325), sf::Color(150, 150, 150), 5, sf::Color::Black));
    if (texture.loadFromFile("./asset/sprite/tiles/tile1.png") == false)
        throw InterfaceError("Error: tile1.png not found", "Interface");
    sprite.setTexture(texture);
    sprite.setScale(0.32, 0.32);
    // sprite.setColor(sf::Color(255, 255, 255, 150));
    for (int i = 0; i < 6; i++)
        tile_texture_.push_back(sf::Texture());
    if (tile_texture_[0].loadFromFile("./asset/sprite/tiles/tile1.png") == false)
        throw InterfaceError("Error: tile1.png not found", "Interface");
    if (tile_texture_[1].loadFromFile("./asset/sprite/tiles/tile2.png") == false)
        throw InterfaceError("Error: tile2.png not found", "Interface");
    if (tile_texture_[2].loadFromFile("./asset/sprite/tiles/tile3.png") == false)
        throw InterfaceError("Error: tile3.png not found", "Interface");
    if (tile_texture_[3].loadFromFile("./asset/sprite/tiles/tile4.png") == false)
        throw InterfaceError("Error: tile4.png not found", "Interface");
    if (tile_texture_[4].loadFromFile("./asset/sprite/tiles/tile5.png") == false)
        throw InterfaceError("Error: tile5.png not found", "Interface");
    if (tile_texture_[5].loadFromFile("./asset/sprite/tiles/tile6.png") == false)
        throw InterfaceError("Error: tile6.png not found", "Interface");
    for (int i = 0; i < 6; i++) {
        tile_sprite_.push_back(sf::Sprite());
        tile_sprite_[i].setTexture(tile_texture_[i]);
        tile_sprite_[i].setScale(0.32, 0.32);
        // tile_sprite_[i].setColor(sf::Color(255, 255, 255, 200));
    }
    for (int i = 0; i < 6; i++)
        tile_iso_texture.push_back(sf::Texture());
    if (tile_iso_texture[0].loadFromFile("./asset/sprite/tiles/tile1w.png") == false)
        throw InterfaceError("Error: tile1w.png not found", "Interface");
    if (tile_iso_texture[1].loadFromFile("./asset/sprite/tiles/tile2w.png") == false)
        throw InterfaceError("Error: tile2w.png not found", "Interface");
    if (tile_iso_texture[2].loadFromFile("./asset/sprite/tiles/tile3w.png") == false)
        throw InterfaceError("Error: tile3w.png not found", "Interface");
    if (tile_iso_texture[3].loadFromFile("./asset/sprite/tiles/tile4w.png") == false)
        throw InterfaceError("Error: tile4w.png not found", "Interface");
    if (tile_iso_texture[4].loadFromFile("./asset/sprite/tiles/tile5w.png") == false)
        throw InterfaceError("Error: tile5w.png not found", "Interface");
    if (tile_iso_texture[5].loadFromFile("./asset/sprite/tiles/tile6w.png") == false)
        throw InterfaceError("Error: tile6w.png not found", "Interface");
    for (int i = 0; i < 6; i++) {
        tile_iso_sprite.push_back(sf::Sprite());
        tile_iso_sprite[i].setTexture(tile_iso_texture[i]);
        tile_iso_sprite[i].setScale(0.32, 0.32);
        tile_iso_sprite[i].setColor(sf::Color(255, 255, 255, 230));
    }
    font.loadFromFile("./asset/gui/Pacifico.ttf");
    if (font.loadFromFile("./asset/gui/Pacifico.ttf") == false)
        throw InterfaceError("Error: Pacifico.ttf not found", "Interface");
    Texts.push_back(sf::Text("tick", font, 50));
    Texts.push_back(sf::Text("Team: ", font, 50));
    for (int i = 0; i < 20; i++) {
        info.push_back(sf::Text("", font, 45));
        info[i].setFillColor(sf::Color::Black);
    }
    Texts[0].setFillColor(sf::Color::Black);
    Texts[1].setFillColor(sf::Color::Black);
    Texts[0].setPosition(1750, 225);
    Texts[1].setPosition(10, 50);
    if (sound_.loadFromFile("./asset/gui/logo_son.jpg") == false)
        throw InterfaceError("Error: logo_son.jpg not found", "Interface");
    sound.setTexture(sound_);
    sound.setPosition(1725, 10);
    sound.setScale(0.3, 0.3);
    sound.setTextureRect(sf::IntRect(0, 0, 450, 325));
    _rect.push_back(sf::RectangleShape(sf::Vector2f(230, 1080)));
    _rect[0].setFillColor(sf::Color(255, 255, 255));
    _rect.push_back(sf::RectangleShape(sf::Vector2f(1920, 75)));
    _rect[1].setFillColor(sf::Color(255, 255, 255));
    _rect.push_back(sf::RectangleShape(sf::Vector2f(230, 1080)));
    _rect[2].setFillColor(sf::Color(255, 255, 255));
    _rect[2].setPosition(1920 - 230, 0);
    _rect.push_back(sf::RectangleShape(sf::Vector2f(1920, 300)));
    _rect[3].setFillColor(sf::Color(255, 255, 255));
    _rect[3].setPosition(0, 1080 - 300);
    zoom = 100;
    last_zoom = 100;
    view.setSize(1920, 1080);
    isPanning = false;
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
        ressource_sprite_.push_back(sf::Sprite());
        info_sprites.push_back(sf::Sprite());
    }
    ressource_sprite_[0].setTexture(ressource_texture[0]);
    ressource_sprite_[0].setScale(0.05, 0.05);
    ressource_sprite_[1].setTexture(ressource_texture[1]);
    ressource_sprite_[1].setScale(0.015, 0.015);
    ressource_sprite_[2].setTexture(ressource_texture[2]);
    ressource_sprite_[2].setScale(0.025, 0.025);
    ressource_sprite_[3].setTexture(ressource_texture[3]);
    ressource_sprite_[3].setScale(0.05, 0.05);
    ressource_sprite_[4].setTexture(ressource_texture[4]);
    ressource_sprite_[4].setScale(0.05, 0.05);
    ressource_sprite_[5].setTexture(ressource_texture[5]);
    ressource_sprite_[5].setScale(0.05, 0.05);
    ressource_sprite_[6].setTexture(ressource_texture[6]);
    ressource_sprite_[6].setScale(0.05, 0.05);
    for (int i = 0; i < 7; i++) {
        info_sprites[i].setTexture(ressource_texture[i]);
        info_sprites[i].setScale(ressource_sprite_[i].getScale().x * 3, ressource_sprite_[i].getScale().y * 3);
    }
    if (egg_texture.loadFromFile("./asset/sprite/egg.png") == false)
        throw InterfaceError("Error: egg.png not found", "Interface");
    for (int i = 0; i < 8; i++)
        player_textures.push_back(sf::Texture());
    if (player_textures[0].loadFromFile("./asset/sprite/rank/rank1.png") == false)
        throw InterfaceError("Error: rank1.png not found", "Interface");
    if (player_textures[1].loadFromFile("./asset/sprite/rank/rank2.png") == false)
        throw InterfaceError("Error: rank2.png not found", "Interface");
    if (player_textures[2].loadFromFile("./asset/sprite/rank/rank3.png") == false)
        throw InterfaceError("Error: rank3.png not found", "Interface");
    if (player_textures[3].loadFromFile("./asset/sprite/rank/rank4.png") == false)
        throw InterfaceError("Error: rank4.png not found", "Interface");
    if (player_textures[4].loadFromFile("./asset/sprite/rank/rank5.png") == false)
        throw InterfaceError("Error: rank5.png not found", "Interface");
    if (player_textures[5].loadFromFile("./asset/sprite/rank/rank6.png") == false)
        throw InterfaceError("Error: rank6.png not found", "Interface");
    if (player_textures[6].loadFromFile("./asset/sprite/rank/rank7.png") == false)
        throw InterfaceError("Error: rank7.png not found", "Interface");
    if (player_textures[7].loadFromFile("./asset/sprite/rank/rank8.png") == false)
        throw InterfaceError("Error: rank8.png not found", "Interface");
    for (int i = 0; i < 4; i++) {
        player_orientation.push_back(std::array<sf::IntRect, 4>());
    }
    player_orientation[0][0] = sf::IntRect(30, 65, 35, 35);
    player_orientation[0][1] = sf::IntRect(30, 100, 35, 35);
    player_orientation[0][2] = sf::IntRect(30, 65, 35, 35);
    player_orientation[0][2] = sf::IntRect(35, 0, 35, 35);
    player_orientation[0][3] = sf::IntRect(35, 35, 30, 30);
    player_orientation[1][0] = sf::IntRect(30, 65, 35, 35);
    player_orientation[1][1] = sf::IntRect(30, 100, 35, 35);
    player_orientation[1][2] = sf::IntRect(35, 0, 35, 35);
    player_orientation[1][3] = sf::IntRect(35, 35, 30, 30);
    player_orientation[2][0] = sf::IntRect(182, 137, 19, 29);
    player_orientation[2][1] = sf::IntRect(178, 217, 27, 26);
    player_orientation[2][2] = sf::IntRect(178, 51, 20, 27);
    player_orientation[2][3] = sf::IntRect(207, 293, 28, 23);
    player_orientation[3][0] = sf::IntRect(53, 801, 21, 55);
    player_orientation[3][1] = sf::IntRect(39, 935, 54, 51);
    player_orientation[3][2] = sf::IntRect(53, 538, 21, 66);
    player_orientation[3][3] = sf::IntRect(35, 678, 53, 51);
    
    

    rect = sf::RectangleShape(sf::Vector2f(102.4, 102.4));
    rect.setFillColor(sf::Color(150, 150, 150, 150));
}

void Zappy::Interface::set_scale_of_player(int i)
{
    if (_gui_connect->_players[i]->getLevel() == 1)
        player_sprites[i].setScale(2, 2);
    else if (_gui_connect->_players[i]->getLevel() == 2)
        player_sprites[i].setScale(2, 2);
    else if (_gui_connect->_players[i]->getLevel() == 4)
        player_sprites[i].setScale(0.5, 0.5);
}

void Zappy::Interface::print_players()
{
    for (int i = 0; i < _gui_connect->_players.size(); i++) {
        if (player_sprites.size() < _gui_connect->_players.size())
            player_sprites.push_back(sf::Sprite());
        player_sprites[i].setTexture(player_textures[_gui_connect->_players[i]->getLevel() - 1]);
        set_scale_of_player(i);
        player_sprites[i].setPosition(_gui_connect->_players[i]->getPosition()[0] * 102.4 + 100, _gui_connect->_players[i]->getPosition()[1] * 102.4 + 150);
        player_sprites[i].setTextureRect(player_orientation[_gui_connect->_players[i]->getLevel() - 1][_gui_connect->_players[i]->getOrientation() + 1]);
        std::cout << "player is in position: " << _gui_connect->_players[i]->getPosition()[0] << " " << _gui_connect->_players[i]->getPosition()[1] << std::endl;
        std::cout << "player is in orientation: " << _gui_connect->_players[i]->getOrientation() << std::endl;
        window->draw(player_sprites[i]);
    }
}

Zappy::Interface::~Interface()
{
    window->close();
    if (_gui_connect != nullptr)
        _gui_connect->close_thread();
    if (ReceiveProcess.joinable())
        ReceiveProcess.join();
}

void Zappy::Interface::print_sound()
{
    if (sound_volume == 0)
        sound.setTextureRect(sf::IntRect(0, 360, 450, 325));
    else if (sound_volume < 75)
        sound.setTextureRect(sf::IntRect(895, 0, 450, 325));
    else if (sound_volume > 75 && sound_volume < 150)
        sound.setTextureRect(sf::IntRect(480, 20, 410, 325));
    else if (sound_volume > 150)
        sound.setTextureRect(sf::IntRect(0, 20, 450, 325));
}

void Zappy::Interface::set_map()
{
    for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
        std::vector<std::shared_ptr<Tile>> tmp;
        std::vector<sf::Sprite> tmp_sprite;
        std::vector<sf::Sprite> tmp_iso_sprite;
        std::vector<std::vector<sf::Sprite>> tmp_ressource_sprite;
        for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
            tmp.push_back(std::make_shared<Tile>(sf::Vector2f(i, j), std::make_shared<Inventory>()));
            int random_index = rand() % 6;
            tmp_sprite.push_back(tile_sprite_[random_index]);
            tmp_iso_sprite.push_back(tile_iso_sprite[random_index]);
            tmp_sprite[j].setPosition(i + 100, j + 100);
            tmp_ressource_sprite.push_back(ressource_sprite_);
        }
        _gui_connect->_tiles.push_back(tmp);
        map_sprites.push_back(tmp_sprite);
        map_iso_sprites.push_back(tmp_iso_sprite);
        ressource_sprite.push_back(tmp_ressource_sprite);
    }
}

void Zappy::Interface::print_resssource()
{
    for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
        for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
            if (i < ressource_sprite.size() && j < ressource_sprite[i].size()) {
                ressource_sprite[i][j][6].setPosition(110 + (i * 102.4), 160 + (j * 102.4));
                if (_gui_connect->_tiles[i][j]->_inventory->get("Food") > 0) {
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Food") > 1)
                        ressource_sprite[i][j][6].setScale(0.05 * (_gui_connect->_tiles[i][j]->_inventory->get("Food")), 0.05 * (_gui_connect->_tiles[i][j]->_inventory->get("Food")));
                    else
                        ressource_sprite[i][j][6].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][6]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Linemate") > 0) {
                    ressource_sprite[i][j][0].setPosition(130 + (i * 102.4), 160 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Linemate") > 1)
                        ressource_sprite[i][j][0].setScale(0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Linemate")) * 0.5), 0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Linemate")) * 0.5));
                    else
                        ressource_sprite[i][j][0].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][0]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Deraumere") > 0) {
                    ressource_sprite[i][j][1].setPosition(160 + (i * 102.4), 160 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Deraumere") > 1)
                        ressource_sprite[i][j][1].setScale(0.025 * ((_gui_connect->_tiles[i][j]->_inventory->get("Deraumere")) * 0.75), 0.025 * ((_gui_connect->_tiles[i][j]->_inventory->get("Deraumere")) * 0.75));
                    else
                        ressource_sprite[i][j][1].setScale(0.025, 0.025);
                    window->draw(ressource_sprite[i][j][1]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Sibur") > 0) {
                    ressource_sprite[i][j][2].setPosition(160 + (i * 102.4), 200 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Sibur") > 1)
                        ressource_sprite[i][j][2].setScale(0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Sibur")) * 0.75), 0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Sibur")) * 0.75));
                    else
                        ressource_sprite[i][j][6].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][2]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Mendiane") > 0) {
                    ressource_sprite[i][j][3].setPosition(110 + (i * 102.4), 200 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Mendiane") > 1)
                        ressource_sprite[i][j][3].setScale(0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Mendiane")) * 0.75), 0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Mendiane")) * 0.75));
                    else
                        ressource_sprite[i][j][6].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][3]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Phiras") > 0) {
                    ressource_sprite[i][j][4].setPosition(120 + (i * 102.4), 200 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Phiras") > 1)
                        ressource_sprite[i][j][4].setScale(0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Phiras")) * 0.75), 0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Phiras")) * 0.75));
                    else
                        ressource_sprite[i][j][6].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][4]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Thystame") > 0) {
                    ressource_sprite[i][j][5].setPosition(140 + (i * 102.4), 200 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Thystame") > 1)
                        ressource_sprite[i][j][5].setScale(0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Thystame")) * 0.75), 0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Thystame")) * 0.75));
                    else
                        ressource_sprite[i][j][6].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][5]);
                }
            }
        }
    }
}

void Zappy::Interface::print_eggs()
{
    for (int i = 0; i < _gui_connect->_eggs.size(); i++) {
        if (egg_sprites.size() < _gui_connect->_eggs.size())
            egg_sprites.push_back(sf::Sprite());
        egg_sprites[i].setTexture(egg_texture);
        egg_sprites[i].setScale(0.05, 0.05);
        egg_sprites[i].setPosition(_gui_connect->_eggs[i]->getPosition()[0] * 102.4 + 135, _gui_connect->_eggs[i]->getPosition()[1] * 102.4 + 217);
        window->draw(egg_sprites[i]);
    }
}

void Zappy::Interface::check_event()
{
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.delta > 0 && view.getSize().x > 1920 / 5 && view.getSize().y > 1080 / 5) {
                view.zoom(0.9);
                zoom += 1;
            } else if (event.mouseWheelScroll.delta < 0 && view.getSize().x < 1920 * 3 && view.getSize().y < 1080 * 3) {
                view.zoom(1.1);
                zoom -= 1;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 230 && event.mouseButton.x < 1920 - 230 && event.mouseButton.y > 75 && event.mouseButton.y < 1080 - 300) {
                isPanning = true;
                lastMousePos = sf::Mouse::getPosition(*window);
            }
            sf::Vector2f mousePos = window->mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y), view);
            for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
                for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
                    sf::FloatRect tileBounds(100 + (i * 102.4), 150 + (j * 102.4), 102.4, 102.4);
                    if (tileBounds.contains(mousePos)) {
                        info[0].setString("Tile: x " + std::to_string(i + 1) + " y " + std::to_string(j + 1));
                        info[1].setString("Player: " + std::to_string(_gui_connect->_tiles[i][j]->_players.size()));
                        info[2].setString("Food: " + std::to_string(_gui_connect->_tiles[i][j]->_inventory->get("Food")));
                        info[3].setString("Linemate: " + std::to_string(_gui_connect->_tiles[i][j]->_inventory->get("Linemate")));
                        info[4].setString("Deraumere: " + std::to_string(_gui_connect->_tiles[i][j]->_inventory->get("Deraumere")));
                        info[5].setString("Sibur: " + std::to_string(_gui_connect->_tiles[i][j]->_inventory->get("Sibur")));
                        info[6].setString("Mendiane: " + std::to_string(_gui_connect->_tiles[i][j]->_inventory->get("Mendiane")));
                        info[7].setString("Phiras: " + std::to_string(_gui_connect->_tiles[i][j]->_inventory->get("Phiras")));
                        info[8].setString("Thystame: " + std::to_string(_gui_connect->_tiles[i][j]->_inventory->get("Thystame")));
                        info[0].setPosition(230, 1080 - 300);
                        info[1].setPosition(230, 1080 - 250);
                        info[2].setPosition(230, 1080 - 200);
                        info_sprites[0].setPosition(1130, 1080 - 300);
                        info[3].setPosition(1230, 1080 - 300);
                        info_sprites[1].setPosition(1130, 1080 - 250);
                        info[4].setPosition(1230, 1080 - 250);
                        info_sprites[2].setPosition(1130, 1080 - 200);
                        info[5].setPosition(1230, 1080 - 200);
                        info_sprites[3].setPosition(630, 1080 - 300);
                        info[6].setPosition(730, 1080 - 300);
                        info_sprites[4].setPosition(630, 1080 - 250);
                        info[7].setPosition(730, 1080 - 250);
                        info_sprites[5].setPosition(630, 1080 - 200);
                        info[8].setPosition(730, 1080 - 200);
                        info_ = true;
                    }
                }
            }
        }
        sf::Vector2f mousePos2 = window->mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y), view);
        for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
            for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
                sf::FloatRect tileBounds2(100 + (i * 102.4), 150 + (j * 102.4), 102.4, 102.4);
                if (tileBounds2.contains(mousePos2)) {
                    rect.setPosition(tileBounds2.left, (tileBounds2.top - rect.getSize().y) + 102.4);
                    isOverTile = true;
                }
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                isPanning = false;
            }
        }
        if (event.type == sf::Event::MouseMoved) {
            if (isPanning) {
                sf::Vector2i currentMousePos = sf::Mouse::getPosition(*window);
                sf::Vector2f delta = window->mapPixelToCoords(lastMousePos) - window->mapPixelToCoords(currentMousePos);
                view.move(delta);
                lastMousePos = currentMousePos;
            }
        }
    }
}

void Zappy::Interface::print_map_iso()
{
    for (double i = 0; i < _gui_connect->get_size_map()[0]; i++) {
        for (double j = 0; j < _gui_connect->get_size_map()[1]; j++) {
            map_iso_sprites[i][j].setPosition(100 + (i * 102.4), 150 + (j * 102.4));
            window->draw(map_iso_sprites[i][j]);
        }
    }
}

void Zappy::Interface::loop(std::shared_ptr<GuiConnect> gui_connect)
{
    _gui_connect = gui_connect;
    ReceiveProcess = std::thread(&GuiConnect::receive, gui_connect.get());
    sleep(5);
    set_map();
    view.zoom(0.5);
    playBackgroundMusic("./asset/music/music.ogg");
    while (window->isOpen()) {
        window->clear(sf::Color::Black);
        sound_volume = bars[0]->checkClick(window);
        backgroundMusic.setVolume(sound_volume);
        check_event();
        window->setView(view); 
        for (double i = 0; i < _gui_connect->get_size_map()[0]; i++) {
            for (double j = 0; j < _gui_connect->get_size_map()[1]; j++) {
                map_sprites[i][j].setPosition(100 + (i * 102.4), 150 + (j * 102.4));
                window->draw(map_sprites[i][j]);
            }
        }
        if (isOverTile)
            window->draw(rect);
        print_resssource();
        print_eggs();
        print_players();
        print_map_iso();
        window->setView(window->getDefaultView());
        for (size_t i = 0; i < _rect.size(); i++)
            window->draw(_rect[i]);
        for (size_t i = 0; i < gui_connect->getTeamNames().size(); i++) {
            Texts.push_back(sf::Text(gui_connect->getTeamNames()[i], font, 50));
            Texts[2 + i].setFillColor(sf::Color::Black);
            Texts[2 + i].setPosition(10, 50 + ((2 + i) * 50));
        }
        for (size_t i = 0; i < Texts.size(); i++)
            window->draw(Texts[i]);
        tick = bars[1]->checkClick(window);
        if (tick > 2 && tick != last_tick) {
            _gui_connect->setTimeUnit(std::to_string(tick));
            last_tick = tick;
        }
        printf("timeUnit: %d\n", _gui_connect->_timeUnit);
        bars[0]->displayBar(window);
        bars[1]->displayBar(window);
        window->draw(sound);
        for (int k = 0; k < 9; k++)
            window->draw(info[k]);
        if (info_) 
           for (int k = 0; k < 6; k++)
                window->draw(info_sprites[k]);
        print_sound();
        window->display();
    }
}

void Zappy::Interface::command_handler()
{
}

void Zappy::Interface::playBackgroundMusic(const std::string& filename)
{
    if (!backgroundMusic.openFromFile(filename)) {
        std::cerr << "Error loading music file: " << filename << std::endl;
        return;
    }
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
}
