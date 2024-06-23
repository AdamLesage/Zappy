/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TeamPrint
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../ServerInfo/GuiConnect.hpp"
#include <memory>
#include "InterfaceError.hpp"
#include "Button.hpp"


#ifndef TEAMPRINT_HPP_
#define TEAMPRINT_HPP_

namespace Zappy {
    class TeamPrint {
        public:
            TeamPrint(std::shared_ptr<GuiConnect> guiConnect, std::shared_ptr<sf::RenderWindow> window);
            ~TeamPrint();
            void print_team();
            void display(sf::Event event);
            void print_info(int i, sf::Event event);
            int getLevel(std::string teamName);
        protected:
            std::shared_ptr<GuiConnect> _guiConnect;
            std::shared_ptr<sf::RenderWindow> _window;
            std::vector<std::vector<sf::Text>> team_players;
            std::vector<sf::Text> _teamNames;
            std::vector<std::shared_ptr<Button>> _buttons;
            std::vector<bool> print_team_;
            sf::Font font;
            std::vector<std::string> Texts_str;
            std::vector<std::string> teamNames;
            sf::RectangleShape Rectangle;
            std::vector<std::vector<sf::Text>> team_info;
            std::vector<std::string> newteamNames;
            std::shared_ptr<Button> close;
            std::vector<int> players;
            sf::Sprite closeSprite;
            sf::Texture closeTexture;
            std::vector<int> players_by_team;            
        private:
    };
}

#endif /* !TEAMPRINT_HPP_ */
