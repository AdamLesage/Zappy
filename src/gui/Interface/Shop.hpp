/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Shop
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../ServerInfo/GuiConnect.hpp"
#include "Button.hpp"
#include "PlayerPrint.hpp"
#include <memory>
#include "InterfaceError.hpp"


#ifndef SHOP_HPP_
#define SHOP_HPP_

namespace Zappy {
    class Shop {
        public:
            Shop(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<PlayerPrint> playerPrint);
            ~Shop();
            void display();
            void start() { isRunning = true; }
        protected:
            std::shared_ptr<PlayerPrint> _playerPrint;
            bool isRunning;
            std::shared_ptr<sf::RenderWindow> _window;
            sf::Font font;
            std::vector<std::string> skins;
            std::vector<sf::Text> texts;
            std::vector<sf::Texture> loading_texture;
            sf::RectangleShape loading;
            std::vector<sf::Text> pplayer_rank_text;
            std::vector<std::shared_ptr<Button>> buttons;
            sf::Event event;
            sf::RectangleShape shoprect;
            std::shared_ptr<Button> close;
            sf::Sprite closeSprite;
            sf::Texture closeTexture;
            std::vector<sf::Sprite> skinsSprite;
            std::vector<sf::Texture> skinsTexture;
            std::vector<sf::IntRect> skinsRect;
        private:
    };
}

#endif /* !SHOP_HPP_ */
