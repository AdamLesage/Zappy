/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** InfoDisplay
*/
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../ServerInfo/GuiConnect.hpp"
#include <memory>
#include "InterfaceError.hpp"

#ifndef INFODISPLAY_HPP_
#define INFODISPLAY_HPP_

namespace Zappy {
    class InfoDisplay {
        public:
            InfoDisplay(std::shared_ptr<GuiConnect> guiConnect, std::shared_ptr<sf::RenderWindow> window, std::vector<sf::Sprite> ressource_sprite_);
            ~InfoDisplay();
            void Checkclick(sf::Vector2f mousePos);
            void display();
            int get_food();
            int get_Linemate();
            int get_Deraumere();
            int get_Sibur();
            int get_Mendiane();
            int get_Phiras();
            int get_Thystame();
        protected:
            bool info_;
            std::vector<sf::Text> info;
            std::shared_ptr<GuiConnect> _guiConnect;
            std::shared_ptr<sf::RenderWindow> _window;
            int current_player_index;
            sf::Font font;
            std::vector<sf::Sprite> info_sprites;
            std::vector<sf::Texture> ressource_texture;
        private:
    };
}

#endif /* !INFODISPLAY_HPP_ */
