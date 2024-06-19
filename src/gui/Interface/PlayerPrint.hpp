/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PlayerPrint
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../ServerInfo/GuiConnect.hpp"
#include <memory>
#include "InterfaceError.hpp"


#ifndef PLAYERPRINT_HPP_
#define PLAYERPRINT_HPP_

namespace zappy {

class PlayerPrint {
    public:
        PlayerPrint(std::shared_ptr<GuiConnect> guiConnect, std::shared_ptr<sf::RenderWindow> window);
        ~PlayerPrint();
        void display();

    protected:
        std::shared_ptr<GuiConnect> _guiConnect;
        std::shared_ptr<sf::RenderWindow> _window;
        std::vector<sf::Sprite> player_sprites;
        std::vector<std::array<sf::IntRect, 4>> player_orientation;
        std::vector<std::array<std::array<sf::IntRect, 8>, 4>> player_animation;
        std::vector<sf::Texture> player_textures;
    private:
};

}

#endif /* !PLAYERPRINT_HPP_ */