/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Credit
*/

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
#include "Button.hpp"
#include <iostream>
#include <vector>

#ifndef CREDIT_HPP_
#define CREDIT_HPP_
namespace Zappy {
    class Credit {
        public:
            Credit(std::shared_ptr<sf::RenderWindow> window);
            ~Credit();
            void start() { isRunning = true; }
            void run();
        protected:
            bool isRunning;
            std::shared_ptr<sf::RenderWindow> _window;
            sf::Font font;
            std::vector<std::string> credits;
            std::vector<sf::Text> texts;
        private:
    };
}

#endif /* !CREDIT_HPP_ */
