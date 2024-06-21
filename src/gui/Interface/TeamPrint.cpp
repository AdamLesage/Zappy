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
    Rectangle.setPosition(220, 140);
    Rectangle.setOutlineThickness(5);
    Rectangle.setOutlineColor(sf::Color::Black);
    if (!font.loadFromFile("./asset/gui/Farmhouse.otf"))
        throw InterfaceError("Error: Farmhouse.otf not found", "Interface");
    closeTexture.loadFromFile("./asset/sprite/close.png");
    closeSprite.setTexture(closeTexture);
}

Zappy::TeamPrint::~TeamPrint()
{
}

int Zappy::TeamPrint::getLevel(std::string teamName)
{
    for (size_t i = 0; i < _guiConnect->_players.size(); i++) {
        if (_guiConnect->_players[i]->getTeamName() == teamName)
            return _guiConnect->_players[i]->getLevel();
    }
    return 0;
}

void Zappy::TeamPrint::print_info(int i)
{
    _window->draw(Rectangle);
    close = std::make_shared<Button>(sf::Vector2f(20, 20), sf::Vector2f(600, 140), sf::Color::White);
    close->setSprite(closeSprite);
    if (close->checkClick(_window) == true)
        print_team_[i] = false;
    close->displayButton(_window);
    players_by_team[i] = 0;
    for (size_t j = 0; j < _guiConnect->_players.size(); j++)
        if (_guiConnect->_players[j]->getTeamName() == teamNames[i])
            players_by_team[i]++;
    for (size_t j = players[i]; j < _guiConnect->_players.size(); j++) {
        if (_guiConnect->_players[j]->getTeamName() == teamNames[i]) {
            if (players[i] < players_by_team[i]) {
                players[i]++;
                team_info[i].push_back(sf::Text("Player " + std::to_string(players[i]), font, 30));
                team_info[i].push_back(sf::Text("Level: " + std::to_string(_guiConnect->_players[j]->getLevel()), font, 30));
            }
        }
    }
    for (size_t k = 0; k < team_info[i].size(); k++) {
        if (k < 18)
            team_info[i][k].setPosition(310, 100 + k * 32);
        else if (k < 36)
            team_info[i][k].setPosition(510, 100 + (k - 18) * 32);
        else
            team_info[i][k].setPosition(710, 100 + (k - 12) * 32);
        team_info[i][k].setFillColor(sf::Color::Black);
        _window->draw(team_info[i][k]);
    }
}

void Zappy::TeamPrint::print_team()
{
    teamNames = _guiConnect->getTeamNames();
    for (size_t i = 0; i < teamNames.size(); i++) {
        if (std::find(Texts_str.begin(), Texts_str.end(), teamNames[i]) == Texts_str.end()) {
            Texts_str.push_back(teamNames[i]);
            players_by_team.push_back(0);
            print_team_.push_back(false);
            team_info.push_back(std::vector<sf::Text>());
            _buttons.push_back(std::make_shared<Button>(sf::Vector2f(200, 50), sf::Vector2f(10, 140 + i * 50), sf::Color::Green, 5, sf::Color::Black));
            _buttons[i]->setText(teamNames[i]);
            players.push_back(0);
        }
    }
}

void Zappy::TeamPrint::display()
{
    for (size_t i = 0; i < _buttons.size(); i++) {
        if (_buttons[i]->checkClick(_window) == true) {
            print_team_[i] = true;
            for (size_t j = 0; j < _buttons.size(); j++) {
                if (j != i)
                    print_team_[j] = false;
            }
        }
        _buttons[i]->displayButton(_window);
        if (print_team_[i] == true)
            print_info(i);
            else {
                players[i] = 0;
                team_info[i].clear();
            }
    }
}
