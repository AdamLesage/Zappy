/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Evolution
*/

#include "Evolution.hpp"

/**
 * @brief Example of how to use the Evolution class.
 * @brief First you need to set the frame info with the setFrameInfo method.
 * @brief Then you can use the updateClock method to update the frame of the sprite.
 * @brief Finally you can draw the sprite with the draw method.
 * 
 */
/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Evolution 1");
    Evolution evol1(std::make_pair(50, 100), std::make_pair(1, 1), sf::Clock(), "asset/sprite/animation/evolution1.png");
    int currentFrame {0};

    evol1.setFrameInfo(82, 67, 16, 2);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        evol1.updateClock(currentFrame, 0.1);
        window.clear();
        evol1.draw(&window);
        window.display();
    }
    return 0;
}
*/

Evolution::Evolution(std::pair<int, int> position, std::pair<float, float> size,
    sf::Clock clock, std::string texture) : _position(position), _size(size), _clock(clock)
{
    _sprite = sf::Sprite();
    _texture = sf::Texture();
    _clock = sf::Clock();
    
    _texture.loadFromFile(texture);
    _sprite.setTexture(_texture);
    _sprite.setPosition(_position.first, _position.second);
    _sprite.setScale(_size.first, _size.second);
}

Evolution::~Evolution()
{
}

std::pair<int, int> Evolution::getPosition() const
{
    return _position;
}

sf::Clock Evolution::getClock() const
{
    return _clock;
}

std::pair<float, float> Evolution::getSize() const
{
    return _size;
}

sf::Sprite Evolution::getSprite() const
{
    return _sprite;
}

int Evolution::getNbrFrame() const
{
    return _nbrFrame;
}

int Evolution::getFrameHight() const
{
    return _frameHeight;
}

int Evolution::getFrameWidth() const
{
    return _frameWidth;
}

void Evolution::setNbrFrame(int nbrFrame)
{
    _nbrFrame = nbrFrame;
}

void Evolution::setFrameHight(int frameHight)
{
    _frameHeight = frameHight;
}

void Evolution::setFrameWidth(int frameWidth)
{
    _frameWidth = frameWidth;
}

void Evolution::setPosition(int x, int y)
{
    _position.first = x;
    _position.second = y;
    _sprite.setPosition(_position.first, _position.second);
}

void Evolution::setClock(sf::Clock clock)
{
    _clock = clock;
}

void Evolution::setSize(float x, float y)
{
    _size.first = x;
    _size.second = y;
}

void Evolution::setFrameInfo(int frameWidth, int frameHeight, int nbrFrame, int numRow)
{
    _frameWidth = frameWidth;
    _frameHeight = frameHeight;
    _nbrFrame = nbrFrame;

    for (int y = 0; y < numRow; ++y) {
        for (int x = 0; x < _nbrFrame / numRow; ++x) {
            _frames.push_back(sf::IntRect(x * (_frameWidth + 36), y * (_frameHeight + 33), _frameWidth, _frameHeight));
        }
    }
    _sprite.setTextureRect(_frames[0]);
}

void Evolution::draw(sf::RenderWindow *window)
{
    window->draw(_sprite);
}

bool Evolution::updateClock(int &currentFrame, float frameTime)
{
    if (_clock.getElapsedTime().asSeconds() > frameTime) {
        currentFrame = (currentFrame + 1) % _nbrFrame;
        _sprite.setTextureRect(_frames[currentFrame]);
        _clock.restart();
        return true;
    }
    return false;
}

void Evolution::updateFrame(int &currentFrame)
{
    currentFrame = (currentFrame + 1) % _nbrFrame;
    _sprite.setTextureRect(_frames[currentFrame]);
}
