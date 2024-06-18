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
        Evolution(std::pair<int, int> position, std::pair<float, float> size,
            sf::Clock clock, std::string texture);
    
    // Dtor
        ~Evolution();

    // Getters
    std::pair<int, int> getPosition() const;
    sf::Clock getClock() const;
    std::pair<float, float> getSize() const;
    int getNbrFrame() const;
    int getFrameHight() const;
    int getFrameWidth() const;

    // Setters
    void setPosition(int x, int y);
    void setClock(sf::Clock clock);
    void setSize(float x, float y);
    void setNbrFrame(int nbrFrame);
    void setFrameHight(int frameHight);
    void setFrameWidth(int frameWidth);
    void setFrameInfo(int frameWidth, int frameHeight, int nbrFrame, int numRow);

    // Member functions
    void draw(sf::RenderWindow *window);
    void updateClock(int &currentFrame, float frameTime);

    protected:
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Image _image;
        std::pair<int, int> _position;
        std::pair<float, float> _size;
        sf::Clock _clock;
        std::vector<sf::IntRect> _frames;
        int _nbrFrame;
        int _frameHeight;
        int _frameWidth;
};
