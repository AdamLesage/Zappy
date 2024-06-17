/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** IEvolution
*/

#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

class IEvolution {
    public:
    // Ctor
        IEvolution() = default;
    
    // Dtor
        ~IEvolution() = default;

    // Getters
    virtual std::pair<int, int> getPosition() const = 0;
    virtual sf::Clock getClock() const = 0;
    virtual std::pair<int, int> getSize() const = 0;

    // Setters
    virtual void setPosition(int x, int y) = 0;
    virtual void setClock(sf::Clock clock) = 0;
    virtual void setSize(int x, int y) = 0;

    // Member functions
    virtual void draw(sf::RenderWindow *window) = 0;

    protected:
    private:
};
