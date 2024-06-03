/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Interface
*/

#include "bar.hpp"
#include "gui_connect.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include <iostream>
#include <thread>
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>


#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

class Interface {
    public:
        Interface();
        ~Interface();
        void loop(std::shared_ptr<GuiConnect> gui_connect);
        void print_sound();
        void command_handler();
        std::array<int, 2> get_mape_size() { return _mape_size; }
        void set_mape_size(std::array<int, 2> mape_size) { _mape_size = mape_size; }
    protected:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Event event;
        std::vector<std::shared_ptr<Bar>> bars;
        int tick;
        int zoom;
        int sound_volume;
        std::array<int, 2> _mape_size;
        std::vector<std::vector<std::shared_ptr<Tile>>> map;
        std::vector<std::vector<sf::Sprite>> map_sprites;
        std::vector<sf::Texture> textures;
        std::vector<std::shared_ptr<Player>> players;
        sf::Font font;
        std::vector<sf::Text> Texts;
        sf::Sprite sound;
        sf::Texture sound_;
        std::shared_ptr<GuiConnect> _gui_connect;
        std::thread ReceiveProcess;
    private:
};

#endif /* !INTERFACE_HPP_ */

