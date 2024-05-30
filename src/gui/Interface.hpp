/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Interface
*/

#include "bar.hpp"
#include "gui_connect.hpp"
#include <iostream>
#include <thread>
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
    protected:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Event event;
        std::vector<std::shared_ptr<Bar>> bars;
        int tick;
        int zoom;
        int sound_volume;
        sf::Sprite sound;
        sf::Texture sound_;
        std::shared_ptr<GuiConnect> _gui_connect;
        std::thread ReceiveProcess;
    private:
};

#endif /* !INTERFACE_HPP_ */

