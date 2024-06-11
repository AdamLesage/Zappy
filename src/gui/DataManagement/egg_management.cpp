/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** egg_management
*/

#include "../ServerInfo/GuiConnect.hpp"

void GuiConnect::createEgg(std::vector<std::string> args)
{
    std::shared_ptr<Zappy::Egg> egg = std::make_shared<Zappy::Egg>();
    egg->_eggNb = std::stoi(args[1]);
    egg->setPlayerNumber(std::stoi(args[2]));
    egg->setPosition(std::stoi(args[3]), std::stoi(args[4]));
    std::shared_ptr<Zappy::Player> playertt = std::make_shared<Zappy::Player>();
    for (auto &player : this->_players) {
        if (player->getPlayerNumber() == std::stoi(args[2])) {
            playertt = player;
            break;
        }
    }
    egg->setTeamName(playertt->getTeamName());
    this->_eggs.push_back(egg);
}

void GuiConnect::deleteEgg(std::vector<std::string> args)
{
    for (std::size_t i = 0; i < this->_eggs.size(); i++) {
        if (this->_eggs[i]->_eggNb == std::stoi(args[1])) {
            this->_eggs.erase(this->_eggs.begin() + i);
            return;
        }
    }
}

void GuiConnect::updateEgg(std::vector<std::string> args)
{
    for (std::size_t i = 0; i < this->_eggs.size(); i++) {
        if (this->_eggs[i]->_eggNb == std::stoi(args[1])) {
            this->_eggs[i]->setPosition(std::stoi(args[2]), std::stoi(args[3]));
            return;
        }
    }
}

std::shared_ptr<Zappy::Egg> GuiConnect::getEggByNb(int eggNb)
{
    for (std::size_t i = 0; i < this->_eggs.size(); i++) {
        if (this->_eggs[i]->_eggNb == eggNb) {
            return this->_eggs[i];
        }
    }
    return nullptr;
}
