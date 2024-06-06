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
    window = std::make_shared<sf::RenderWindow>();
    window->create(sf::VideoMode(1920, 1080), "Zappy");
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(20, 50), sf::Vector2f(200, 40), sf::Vector2f(1700, 125), sf::Color(150, 150, 150), 5, sf::Color::Black));
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(20, 50), sf::Vector2f(200, 40), sf::Vector2f(1700, 325), sf::Color(150, 150, 150), 5, sf::Color::Black));
    texture.loadFromFile("./asset/spirte/decoration/tiles.png");
    textures.push_back(texture);
    sprite.setTexture(texture);
    sprite.setScale(0.1, 0.1);
    font.loadFromFile("./asset/gui/Pacifico.ttf");
    Texts.push_back(sf::Text("tick", font, 50));
    Texts.push_back(sf::Text("Team: ", font, 50));
    Texts[0].setFillColor(sf::Color::Black);
    Texts[1].setFillColor(sf::Color::Black);
    Texts[0].setPosition(1750, 225);
    Texts[1].setPosition(10, 50);
    sound_.loadFromFile("./asset/gui/logo_son.jpg");
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
    // view.move(100, 100);
    // view.setRotation(20);
    // view.rotate(5);
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
        for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
            tmp.push_back(std::make_shared<Tile>(sf::Vector2f(i, j), std::make_shared<Inventory>()));
            tmp_sprite.push_back(sprite);
            tmp_sprite[j].setPosition(i + 100, j + 100);
        }
        map.push_back(tmp);
        map_sprites.push_back(tmp_sprite);
    }
}

void Zappy::Interface::loop(std::shared_ptr<GuiConnect> gui_connect)
{
    _gui_connect = gui_connect;
    ReceiveProcess = std::thread(&GuiConnect::receive, gui_connect.get());
    sleep(5);
    set_map();
    
    bool isPanning = false;

    while (window->isOpen()) {
        window->clear(sf::Color::Black);
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0 && view.getSize().x > 960 && view.getSize().y > 540) {
                    view.zoom(0.9);
                    printf("zoom: %f\n", zoom);
                    zoom += 1;
                } else if (view.getSize().x < 1920 * 3 && view.getSize().y < 1080 * 3) {
                    view.zoom(1.1);
                    printf("zoom: %f\n", zoom);
                    zoom -= 1;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 230 && event.mouseButton.x < 1920 - 230 && event.mouseButton.y > 75 && event.mouseButton.y < 1080 - 300) {
                    isPanning = true;
                    lastMousePos = sf::Mouse::getPosition(*window);
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
        sound_volume = bars[0]->checkClick(window);
        window->setView(view);        
        for (double i = 0; i < _gui_connect->get_size_map()[0]; i++) {
            for (double j = 0; j < _gui_connect->get_size_map()[1]; j++) {
                map_sprites[i][j].setPosition(500 + (i * 102.4), 150 + (j * 102.4));
                window->draw(map_sprites[i][j]);
            }
        }
        window->setView(window->getDefaultView());
        for (size_t i = 0; i < _rect.size(); i++)
            window->draw(_rect[i]);
        // printf("----------------------------------------------------------------------------------------\n");
        printf("%ld", _gui_connect->get_team_names().size());
        for (size_t i = 0; i < gui_connect->get_team_names().size(); i++) {
            Texts.push_back(sf::Text(gui_connect->get_team_names()[i], font, 50));
            printf("team[%ld]: %s\n", i, gui_connect->get_team_names()[i].c_str());
            Texts[2 + i].setFillColor(sf::Color::Black);
            Texts[2 + i].setPosition(10, 50 + (2 + i * 50));
        }
        for (size_t i = 0; i < Texts.size(); i++)
            window->draw(Texts[i]);
        bars[1]->checkClick(window);
        bars[0]->displayBar(window);
        bars[1]->displayBar(window);
        window->draw(sound);
        print_sound();
        window->display();
    }
}


void Zappy::Interface::command_handler()
{
}