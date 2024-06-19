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


#ifndef TEAMPRINT_HPP_
#define TEAMPRINT_HPP_

class TeamPrint {
    public:
        TeamPrint();
        ~TeamPrint();

    protected:
        std::shared_ptr<GuiConnect> _guiConnect;
        std::shared_ptr<sf::RenderWindow> _window;

    private:
};

#endif /* !TEAMPRINT_HPP_ */
