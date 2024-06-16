/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Evolution
*/

#pragma once

#include "IEvolution.hpp"

class Evolution : public IEvolution {
    public:
    // Ctor
        Evolution(std::pair<int, int> position, std::pair<int, int> size,
            sf::Clock clock) : _position(position), _size(size), _clock(clock) {};
    
    // Dtor
        ~Evolution();

    // Getters
    std::pair<int, int> getPosition() const;
    sf::Clock getClock() const;
    std::pair<int, int> getSize() const;

    // Setters
    void setPosition(int x, int y);
    void setClock(sf::Clock clock);
    void setSize(int x, int y);

    // Member functions

    protected:
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Image _image;
        std::pair<int, int> _position;
        std::pair<int, int> _size;
        sf::Clock _clock;
};
