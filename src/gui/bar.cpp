/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** bar
*/

#include "bar.hpp"

Bar::Bar(sf::Vector2f size, sf::Vector2f size_back, sf::Vector2f pos, sf::Color color, int outline, sf::Color outlineColor)
{
    this->shape.setSize(size);
    this->back_shape.setSize(size_back);
    this->barSize = pos.x + size_back.x - size.x + outline;
    this->shape.setOutlineThickness(outline);
    this->back_shape.setOutlineThickness(outline);
    this->shape.setOutlineColor(outlineColor);
    this->back_shape.setOutlineColor(outlineColor);
    this->shape.setPosition(pos.x, pos.y);
    this->back_shape.setPosition(pos.x, pos.y + 2.5);
    this->shape.setFillColor(color);
    this->back_shape.setFillColor(color);
    this->hoverSape.setSize(size);
    this->hoverSape.setPosition(pos.x, pos.y);
    this->hoverSape.setFillColor(sf::Color::Black);
    this->_characterSize = 0;
    this->_pos = pos;
}

Bar::~Bar()
{
}

bool Bar::checkClick(std::shared_ptr<sf::RenderWindow> window)
{
    sf::Mouse mouse;
    sf::Vector2f mousPos;
    mousPos.x = mouse.getPosition(*window.get()).x;
    mousPos.y = mouse.getPosition(*window.get()).y;
    this->setState(StateBar::None);
    if (this->shape.getGlobalBounds().contains(mousPos)) {
        this->setState(StateBar::Hover);
        if (mouse.isButtonPressed(sf::Mouse::Button::Left)) {
            this->setState(StateBar::Clicked);
            sf::Vector2f newPos = {mousPos.x - this->shape.getSize().x / 2, _pos.y};
            if (newPos.x < _pos.x)
                newPos.x = _pos.x;
            if (newPos.x < barSize) {
                this->shape.setPosition(newPos);
                this->hoverSape.setPosition(newPos);
            }
            return (true);
        }
    }
    return (false);
}

void Bar::displayBar(std::shared_ptr<sf::RenderWindow> window)
{
    std::string font_path("./asset/gui/Pacifico.ttf");
    sf::Font font;
    sf::Color color = this->hoverSape.getFillColor();

    if (this->state ==  StateBar::None) {
        color.a = 0;
        this->hoverSape.setFillColor(color);
    } else if (this->state == StateBar::Hover) {
        color.a = 30;
        this->hoverSape.setFillColor(color);
    } else {
        color.a = 50;
        this->hoverSape.setFillColor(color);
    }
    this->shape.setTexture(&this->Texture);
    window->draw(this->back_shape);
    window->draw(this->shape);
    if (font.loadFromFile(font_path)) {
        this->renderText.setFont(font);
        this->renderText.setCharacterSize(this->_characterSize);
        this->renderText.setFillColor(sf::Color::Black);
        this->renderText.setPosition(this->shape.getGlobalBounds().left + (this->shape.getGlobalBounds().width - this->renderText.getGlobalBounds().width) / 2,
            this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height / 4);
    }
    window->draw(this->renderText);
    window->draw(this->hoverSape);
}

void Bar::setState(StateBar newState)
{
    this->state = newState;
}

void Bar::setPosition(sf::Vector2f pos)
{
    this->shape.setPosition(pos);
    this->hoverSape.setPosition(pos);
}

void Bar::setSprite(sf::Sprite sprite)
{
    this->Texture.loadFromImage(sprite.getTexture()->copyToImage());
}