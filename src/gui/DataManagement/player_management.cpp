/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** player_management
*/

#include "../ServerInfo/GuiConnect.hpp"

void GuiConnect::createPlayer(std::vector<std::string> args)
{
    // args format vector<string> = {"commandName", "playerNumber", "x", "y", "orientation", "level", "teamName"}
    if (args.size() != 3)
        return;
    std::shared_ptr<Zappy::Player> player = std::make_shared<Zappy::Player>();
    player->setPlayerNumber(std::stoi(args[1]));
    player->setPosition(std::stoi(args[2]), std::stoi(args[3]));
    player->setOrientation(args[4]);
    player->setPlayerLevel(std::stoi(args[5]));
    player->setTeamName(args[6]);
    this->_players.push_back(player);
}

void GuiConnect::deletePlayer(int playerNb)
{
    for (std::size_t i = 0; i < this->_players.size(); i++) {
        if (this->_players[i]->getPlayerNumber() == playerNb) {
            this->_players.erase(this->_players.begin() + i);
            return;
        }
    }
}

void GuiConnect::updatePlayerCoords(std::pair<int, int> coords, int playerNb)
{
    for (std::size_t i = 0; i < this->_players.size(); i++) {
        if (this->_players[i]->getPlayerNumber() == playerNb) {
            this->_players[i]->setPosition(coords.first, coords.second);
            return;
        }
    }
}

std::pair<int, int> GuiConnect::getPlayerCoords(int playerNb)
{
    for (std::size_t i = 0; i < this->_players.size(); i++) {
        if (this->_players[i]->getPlayerNumber() == playerNb) {
            return std::make_pair(this->_players[i]->getPosition()[0], this->_players[i]->getPosition()[1]);
        }
    }
    return std::make_pair(-1, -1);
}

void GuiConnect::updatePlayerInventory(int playerNb, std::shared_ptr<Zappy::Inventory> inventory)
{
    for (std::size_t i = 0; i < this->_players.size(); i++) {
        if (this->_players[i]->getPlayerNumber() == playerNb) {
            this->_players[i]->setInventory(inventory);
            return;
        }
    }
}


std::shared_ptr<Zappy::Inventory> GuiConnect::getPlayerInventory(int playerNb)
{
    std::shared_ptr<Zappy::Player> player = getPlayerByNb(playerNb);

    if (player == nullptr)
        return nullptr;
    return player->getInventory();
}

std::string GuiConnect::getPlayerTeam(int playerNb)
{
    for (std::size_t i = 0; i < this->_players.size(); i++) {
        if (this->_players[i]->getPlayerNumber() == playerNb) {
            return this->_players[i]->getTeamName();
        }
    }
    return "";
}

void GuiConnect::updatePlayerTeam(int playerNb, std::string teamName)
{
    for (std::size_t i = 0; i < this->_players.size(); i++) {
        if (this->_players[i]->getPlayerNumber() == playerNb) {
            this->_players[i]->setTeamName(teamName);
            return;
        }
    }
}

void GuiConnect::updatePlayerLevel(int playerNb, int level)
{
    for (std::size_t i = 0; i < this->_players.size(); i++) {
        if (this->_players[i]->getPlayerNumber() == playerNb) {
            this->_players[i]->setPlayerLevel(level);
            return;
        }
    }
}

int GuiConnect::getPlayerLevel(int playerNb)
{
    for (std::size_t i = 0; i < this->_players.size(); i++) {
        if (this->_players[i]->getPlayerNumber() == playerNb) {
            return this->_players[i]->getLevel();
        }
    }
    return -1;
}

std::shared_ptr<Zappy::Player> GuiConnect::getPlayerByNb(int playerNb)
{
    for (std::size_t i = 0; i < this->_players.size(); i++) {
        if (this->_players[i]->getPlayerNumber() == playerNb) {
            return this->_players[i];
        }
    }
    return nullptr;
}