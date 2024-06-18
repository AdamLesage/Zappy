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
    virtual std::pair<float, float> getSize() const = 0;
    virtual int getNbrFrame() const = 0;
    virtual int getFrameHight() const = 0;
    virtual int getFrameWidth() const = 0;

    // Setters
    virtual void setPosition(int x, int y) = 0;
    virtual void setClock(sf::Clock clock) = 0;
    virtual void setSize(float x, float y) = 0;
    virtual void setNbrFrame(int nbrFrame) = 0;
    virtual void setFrameHight(int frameHight) = 0;
    virtual void setFrameWidth(int frameWidth) = 0;
    virtual void setFrameInfo(int frameWidth, int frameHeight, int nbrFrame, int numRow) = 0;

    // Member functions
    virtual void draw(sf::RenderWindow *window) = 0;
    virtual void updateClock(int &currentFrame, float frameTime) = 0;

    protected:
    private:
};
