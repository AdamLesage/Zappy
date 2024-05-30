/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Interface
*/

#include "bar.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

class Interface {
    public:
        Interface();
        ~Interface();
        void loop();
        void print_sound();
    protected:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Event event;
        std::vector<std::shared_ptr<Bar>> bars;
        int tick;
        int zoom;
        int sound_volume;
        sf::Sprite sound;
        sf::Texture sound_;
    private:
};

#endif /* !INTERFACE_HPP_ */

