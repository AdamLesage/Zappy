/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TeamPrint
*/

#include "TeamPrint.hpp"

Zappy::TeamPrint::TeamPrint(std::shared_ptr<GuiConnect> guiConnect, std::shared_ptr<sf::RenderWindow> window)
{
    _guiConnect = guiConnect;
    _window = window;
    Rectangle.setSize(sf::Vector2f(400, 600));
    Rectangle.setFillColor(sf::Color::Yellow);
    Rectangle.setPosition(300, 50);
    if (!font.loadFromFile("./asset/gui/Farmhouse.otf"))
        throw InterfaceError("Error: Farmhouse.otf not found", "Interface");
}

Zappy::TeamPrint::~TeamPrint()
{
}

void Zappy::TeamPrint::print_info(int i)
{
    _window->draw(Rectangle);
    close = std::make_shared<Button>(sf::Vector2f(15, 15), sf::Vector2f(685, 50), sf::Color::Red, 1, sf::Color::Black);
    close->setText("X", 10);
    if (close->checkClick(_window) == true)
        print_team_[i] = false;
    close->displayButton(_window);
    for (size_t j = 0; j < _guiConnect->_players.size(); j++) {
        if (_guiConnect->_players[j]->getTeamName() == teamNames[i]) {
            printf("teamName: %s\n", teamNames[i].c_str());
            if (players[i] < _guiConnect->_players.size()) {
                players[i]++;  
                team_info.push_back(sf::Text(teamNames[i], font, 30));
                team_info.push_back(sf::Text("Level: " + std::to_string(_guiConnect->_players[j]->getLevel()), font, 30));
                team_info.push_back(sf::Text("X: " + std::to_string(_guiConnect->_players[j]->getPosition()[0]) + "Y: " + std::to_string(_guiConnect->_players[j]->getPosition()[1]), font, 30));
            }
        }
    }
    for (size_t k = 0; k < team_info.size(); k++) {
        team_info[k].setPosition(310, 100 + k * 30);
        team_info[k].setFillColor(sf::Color::Black);
        _window->draw(team_info[k]);
    }
}

void Zappy::TeamPrint::print_team()
{
    teamNames = _guiConnect->getTeamNames();
    for (size_t i = 0; i < teamNames.size(); i++) {
        if (std::find(Texts_str.begin(), Texts_str.end(), teamNames[i]) == Texts_str.end()) {
            Texts_str.push_back(teamNames[i]);
            print_team_.push_back(false);
            _buttons.push_back(std::make_shared<Button>(sf::Vector2f(200, 50), sf::Vector2f(10, 140 + i * 50), sf::Color::Green, 5, sf::Color::Black));
            _buttons[i]->setText(teamNames[i]);
            players.push_back(0);
        }
    }
}

void Zappy::TeamPrint::display()
{
    for (size_t i = 0; i < _buttons.size(); i++) {
        if (_buttons[i]->checkClick(_window) == true)
            print_team_[i] = true;
        _buttons[i]->displayButton(_window);
        if (print_team_[i] == true)
            print_info(i);
    }
}
