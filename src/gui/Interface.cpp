/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Interface
*/

#include <unistd.h>
#include "Interface.hpp"

Interface::Interface()
{
    window = std::make_shared<sf::RenderWindow>();
    window->create(sf::VideoMode(1920, 1080), "Zappy");
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(20, 50), sf::Vector2f(200, 40), sf::Vector2f(1700, 125), sf::Color(150, 150, 150), 5, sf::Color::Black));
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(10, 30), sf::Vector2f(100, 20), sf::Vector2f(100, 200), sf::Color(150, 150, 150), 5, sf::Color::Black));
    texture.loadFromFile("./asset/spirte/decoration/tiles.png");
    textures.push_back(texture);
    sprite.setTexture(texture);
    sprite.setScale(0.1, 0.1);
    font.loadFromFile("./asset/gui/Pacifico.ttf");
    Texts.push_back(sf::Text("size_map", font, 20));
    sound_.loadFromFile("./asset/gui/logo_son.jpg");
    sound.setTexture(sound_);
    sound.setPosition(1725, 10);
    sound.setScale(0.3, 0.3);
    sound.setTextureRect(sf::IntRect(0, 0, 450, 325));
}

Interface::~Interface()
{
    window->close();
    if (_gui_connect != nullptr)
        _gui_connect->close_thread();
    if (ReceiveProcess.joinable())
        ReceiveProcess.join();
}

void Interface::print_sound()
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

void Interface::set_map()
{
    for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
        std::vector<std::shared_ptr<Tile>> tmp;
        std::vector<sf::Sprite> tmp_sprite;
        for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
            tmp.push_back(std::make_shared<Tile>(sf::Vector2f(i, j), std::make_shared<Inventory>()));
            tmp_sprite.push_back(sprite);
            tmp_sprite[j].setPosition(i + 100, j + 100);
        }
        map.push_back(tmp);
        map_sprites.push_back(tmp_sprite);
    }
}

void Interface::loop(std::shared_ptr<GuiConnect> gui_connect)
{
    _gui_connect = gui_connect;
    ReceiveProcess = std::thread(&GuiConnect::receive, gui_connect.get());
    sleep(5);
    set_map();
    while (window->isOpen()) {
        window->clear(sf::Color::White);
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
            for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
                map_sprites[i][j].setPosition( 500 + (i * 100), 150 +  (j * 100));
                window->draw(map_sprites[i][j]);
            }
        }
        sound_volume = bars[0]->checkClick(window);
        bars[1]->checkClick(window);
        bars[0]->displayBar(window);
        bars[1]->displayBar(window);
        Texts[0].setFillColor(sf::Color::Black);
        Texts[0].setString("size_map: " + std::to_string(_gui_connect->get_size_map()[0]) + " | " + std::to_string(_gui_connect->get_size_map()[1]));
        Texts[0].setPosition(500, 50);
        window->draw(Texts[0]);
        window->draw(sound);
        print_sound();
        window->display();
    }
}

void Interface::command_handler()
{
}