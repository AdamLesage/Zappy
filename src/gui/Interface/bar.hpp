/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** bar
*/

#ifndef BAR_HPP_
#define BAR_HPP_

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
    class Bar {
        public:
            enum StateBar {
                None, Hover, Clicked
            };
            Bar(sf::Vector2f size, sf::Vector2f size_back, sf::Vector2f pos, sf::Color color, int outline, sf::Color outlineColor, int origin = 0);
            ~Bar();
            int checkClick(std::shared_ptr<sf::RenderWindow> window);
            bool checkClick2(std::shared_ptr<sf::RenderWindow> window);
            void setPosition(sf::Vector2f pos); // set the position of the Bar
            void setSprite(sf::Sprite sprite); // set the sprite of the Bar
            void displayBar(std::shared_ptr<sf::RenderWindow> window); // display the Bar
        protected:
        private:
            void setState(StateBar); // set the state of the Bar
            float barSize;
            sf::Vector2f _pos;
            StateBar state;
            sf::RectangleShape shape;
            sf::RectangleShape back_shape;
            sf::Texture Texture;
            sf::Text renderText;
            sf::RectangleShape hoverSape;
            size_t _characterSize;
            sf::Vector2f newPos;
    };
}

#endif /* !BAR_HPP_ */
