/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Button
*/


#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <memory>
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

namespace Zappy {
    class Button {
        public:
            enum StateButton {
                None, Hover, Clicked
            };
            Button(sf::Vector2f size, sf::Vector2f pos, sf::Color color,
                int outline = 0, sf::Color outlineColor = sf::Color::Transparent);
            ~Button();
            bool checkClick(std::shared_ptr<sf::RenderWindow> window, sf::Event event); // manage click and hover of the button and change his state
            void setText(std::string, size_t size = 20); // set the text of the button
            void setPosition(sf::Vector2f pos); // set the position of the button
            void setSprite(sf::Sprite sprite); // set the sprite of the button
            void displayButton(std::shared_ptr<sf::RenderWindow> window); // display the Button
            std::string getText() const; // get the value of the button text
        protected:
        private:
            sf::String text;
            void setState(StateButton); // set the state of the button
            StateButton state;
            sf::RectangleShape shape;
            sf::Texture Texture;
            sf::Text renderText;
            sf::RectangleShape hoverSape;
            size_t _characterSize;
    };
};

#endif /* !BUTTON_HPP_ */