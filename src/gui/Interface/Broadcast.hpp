/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Broadcast
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../ServerInfo/GuiConnect.hpp"
#include <memory>
#include "InterfaceError.hpp"
#include <vector>

#ifndef BROADCAST_HPP_
#define BROADCAST_HPP_

namespace Zappy {
    class Broadcast {
        public:
            Broadcast(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<GuiConnect> guiConnect);
            ~Broadcast();
            void display(int i);
            void check_player_broadcast(int i);
        protected:
            sf::Font font;
            std::shared_ptr<GuiConnect> _guiConnect;
            std::shared_ptr<sf::RenderWindow> _window;
            std::vector<sf::Text> _broadcasts_text;
            std::vector<sf::Sprite> _broadcasts_sprites;
            std::vector<sf::Sprite> _broadcasts_messages;
            std::vector<sf::Texture> _broadcasts_textures;
            sf::Clock _clock;
        private:
    };
}

#endif /* !BROADCAST_HPP_ */
