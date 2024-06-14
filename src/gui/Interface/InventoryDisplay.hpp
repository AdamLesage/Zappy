/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** InventoryDisplay
*/

#ifndef INVENTORYDISPLAY_HPP_
#define INVENTORYDISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../ServerInfo/GuiConnect.hpp"
#include <memory>
#include "InterfaceError.hpp"

namespace Zappy {
    class InventoryDisplay {
        public:
            InventoryDisplay(std::shared_ptr<GuiConnect> guiConnect, std::shared_ptr<sf::RenderWindow> window);
            ~InventoryDisplay();
            void display();
            void check_event(sf::Event *event, std::vector<sf::Sprite> players_sprites, sf::View view);
        protected:
        private:
            std::shared_ptr<GuiConnect> _guiConnect;
            std::shared_ptr<sf::RenderWindow> _window;
            int current_player_index;

            sf::Font font;
            sf::RectangleShape back;
            std::vector<sf::Text> playerInfo;
        };
};

#endif /* !InventoryDisplay_HPP_ */
