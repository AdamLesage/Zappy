/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Interface
*/

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

    protected:
        sf::RenderWindow window;
        sf::Event event;
    private:
};

#endif /* !INTERFACE_HPP_ */

