/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Menu
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../ServerInfo/GuiConnect.hpp"
#include "Button.hpp"
#include "Credit.hpp"
#include "PlayerPrint.hpp"
#include <memory>
#include "InterfaceError.hpp"
#include "Shop.hpp"

#ifndef MENU_HPP_
#define MENU_HPP_

namespace Zappy {
    class Menu {
        public:
            Menu(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<PlayerPrint> playerPrint);
            ~Menu();
            void display();

        protected:
            std::shared_ptr<PlayerPrint> _playerPrint;
            std::shared_ptr<sf::RenderWindow> _window;
            std::shared_ptr<GuiConnect> _guiConnect;
            std::vector<sf::Texture> loading_texture;
            sf::RectangleShape loading;
            sf::Clock clock;
            std::shared_ptr<Credit> credit;
            std::shared_ptr<Shop> shop;
            sf::RectangleShape loadingBar;
            std::vector<std::shared_ptr<Button>> buttons;
            std::vector<sf::Text> pplayer_rank_text;
            bool menu;
            sf::Event event;
            sf::Font font;
            sf::Text loadingText;
        private:
    };
}

#endif /* !MENU_HPP_ */
