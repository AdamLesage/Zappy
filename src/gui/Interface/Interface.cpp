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
    TileClicked = false;
    window = std::make_shared<sf::RenderWindow>();
    window->create(sf::VideoMode(1920, 1080), "Zappy");
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(20, 50), sf::Vector2f(200, 40), sf::Vector2f(1700, 125), sf::Color(150, 150, 150), 5, sf::Color::Black));
    loadInerfaceTexture();
    loadResources();
    loadTiles();
    loadTexts();
    loadSound();
    zoom = 100;
    last_zoom = 100;
    view.setSize(1920, 1080);
    isPanning = false;
    rect = sf::RectangleShape(sf::Vector2f(102.4, 102.4));
    rect2 = sf::RectangleShape(sf::Vector2f(102.4, 102.4));
    rect.setFillColor(sf::Color(150, 150, 150, 150));
    rect2.setFillColor(sf::Color(255, 165, 0, 150));
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
        std::vector<sf::Sprite> tmp_sprite;
        std::vector<std::vector<sf::Sprite>> tmp_ressource_sprite;
        for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
            int random_index = rand() % 2;
            tmp_sprite.push_back(tile_sprite_[random_index]);
            tmp_sprite[j].setPosition(i + 100, j + 100);
            tmp_ressource_sprite.push_back(ressource_sprite_);
        }
        map_sprites.push_back(tmp_sprite);
        ressource_sprite.push_back(tmp_ressource_sprite);
    }
}

void Zappy::Interface::draw_resource_sprite(int i, int j, int spriteIndex, const std::string &resourceName, float baseX, float baseY, float scaleFactor) {
    if (_gui_connect->_tiles[i][j]->_inventory->get(resourceName) > 0) {
        ressource_sprite[i][j][spriteIndex].setPosition(baseX + (i * 102.4), baseY + (j * 102.4));
        if (_gui_connect->_tiles[i][j]->_inventory->get(resourceName) > 1)
            ressource_sprite[i][j][spriteIndex].setScale(scaleFactor * ((_gui_connect->_tiles[i][j]->_inventory->get(resourceName)) * 0.75), scaleFactor * ((_gui_connect->_tiles[i][j]->_inventory->get(resourceName)) * 0.75));
        else
            ressource_sprite[i][j][spriteIndex].setScale(scaleFactor, scaleFactor);
        window->draw(ressource_sprite[i][j][spriteIndex]);
    }
}

void Zappy::Interface::print_resssource() {
    for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
        for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
            if ((std::size_t)i < ressource_sprite.size() && (std::size_t)j < ressource_sprite[i].size()) {
                draw_resource_sprite(i, j, 6, "Food", 110, 160, 0.05);
                draw_resource_sprite(i, j, 0, "Linemate", 130, 160, 0.05);
                draw_resource_sprite(i, j, 1, "Deraumere", 160, 160, 0.025);
                draw_resource_sprite(i, j, 2, "Sibur", 160, 200, 0.05);
                draw_resource_sprite(i, j, 3, "Mendiane", 110, 200, 0.05);
                draw_resource_sprite(i, j, 4, "Phiras", 120, 200, 0.05);
                draw_resource_sprite(i, j, 5, "Thystame", 140, 200, 0.05);
            }
        }
    }
}

void Zappy::Interface::print_eggs()
{
    for (int i = 0; (std::size_t)i < _gui_connect->_eggs.size(); i++) {
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
        _inventory->check_event(&event, _playerPrint->getPlayerSprites(), view);
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
            _info->Checkclick(mousePos);
        }
        sf::Vector2f mousePos2 = window->mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y), view);
        for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
            for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
                sf::FloatRect tileBounds2(100 + (i * 102.4), 150 + (j * 102.4), 102.4, 102.4);
                if (tileBounds2.contains(mousePos2)) {
                    rect.setPosition(tileBounds2.left, (tileBounds2.top - rect.getSize().y) + 102.4);
                    isOverTile = true;
                    isOverTile2 = true;
                }
            }
        }
        sf::Vector2f mousePos3 = window->mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y), view);
        for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
            for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
                sf::FloatRect tileBounds2(100 + (i * 102.4), 150 + (j * 102.4), 102.4, 102.4);
                if (tileBounds2.contains(mousePos3) && event.type == sf::Event::MouseButtonPressed) {
                    rect2.setPosition(tileBounds2.left, (tileBounds2.top - rect2.getSize().y) + 102.4);
                    TileClicked = true;
                    TileClicked2 = true;
                }
            }
        }
        if (isOverTile2 == false)
            isOverTile = false;
        isOverTile2 = false;

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

void Zappy::Interface::loop(std::shared_ptr<GuiConnect> gui_connect)
{
    float frameTime = 0.13; // speed of the game

    _gui_connect = gui_connect;
    try {
        this->_inventory.reset(new InventoryDisplay(_gui_connect, window));
        this->_info.reset(new InfoDisplay(_gui_connect, window, ressource_sprite_));
        this->_broadcast.reset(new Broadcast(window, _gui_connect));
        this->_teamPrint.reset(new TeamPrint(_gui_connect, window));
        this->_playerPrint.reset(new PlayerPrint(_gui_connect, window,font,_teamnbr,_broadcast,evolutions));
        this->_menu.reset(new Menu(window, _playerPrint));
    } catch (Zappy::InterfaceError &e) {
        throw Zappy::InterfaceError(e.what(), "Interface");
        return;
    }
    ReceiveProcess = std::thread(&GuiConnect::receive, gui_connect.get());
    printf("start\n");
    window->setFramerateLimit(120);
    this->_menu->display();
    printf("end\n");
    set_map();
    view.zoom(0.5);
    playBackgroundMusic("./asset/music/music.ogg");
    clock.restart();
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(20, 50), sf::Vector2f(200, 40), sf::Vector2f(1700, 325), sf::Color(150, 150, 150), 5, sf::Color::Black, _gui_connect->_timeUnit));
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
        if (TileClicked)
            window->draw(rect2);
        _teamnbr = gui_connect->getTeamNames().size();
        _teamPrint->print_team();
        print_resssource();
        print_eggs();
        _playerPrint->display();
        evolutions = _playerPrint->getEvolutions();
        // if (clock.getElapsedTime().asSeconds() > frameTime) {
        //     int i = 0;
        //     if (evolutions.size() > 0) {
        //         for (auto &it : evolutions) {
        //             if (_gui_connect->_players[i].get()->isPlayerIncanting() == true) {
        //                 it.second->updateFrame(it.first);
        //             }
        //             i++;
        //         }
        //     }
        //     clock.restart();
        // }
        _playerPrint->setEvolutions(evolutions);
        window->setView(window->getDefaultView());
        for (size_t i = 0; i < _rect.size(); i++)
            window->draw(_rect[i]);
        _teamPrint->display();
        for (size_t i = 0; i < Texts.size(); i++)
            window->draw(Texts[i]);
        tick = bars[1]->checkClick(window);
        if (tick > 2 && tick != last_tick) {
            _gui_connect->setTimeUnit(std::to_string(tick));
            last_tick = tick;
        }
        if (tick < 2)
            tick = 2;
        tick_text.setString(std::to_string(_gui_connect->getTimeUnit()));
        window->draw(tick_text);
        bars[0]->displayBar(window);
        bars[1]->displayBar(window);
        window->draw(sound);
        _info->display();
        print_sound();
        this->_inventory->display(_playerPrint->getPlayerSprites());
        window->display();
    }
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
