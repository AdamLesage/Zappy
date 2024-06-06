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

void GuiConnect::deletePlayer(std::vector<std::string> args)
{
    args = args;
}

void GuiConnect::updatePlayerCoords(std::vector<std::string> args)
{
    args = args;
}

void GuiConnect::getPlayerCoords(std::vector<std::string> args)
{
    args = args;
}

void GuiConnect::updatePlayerInventory(std::vector<std::string> args)
{
    args = args;
}

void GuiConnect::createPlayerInventory(std::vector<std::string> args)
{
    args = args;
}

void GuiConnect::getPlayerInventory(std::vector<std::string> args)
{
    args = args;
}

void GuiConnect::getPlayerTeam(std::vector<std::string> args)
{
    args = args;
}

void GuiConnect::updatePlayerTeam(std::vector<std::string> args)
{
    args = args;
}

void GuiConnect::updatePlayerLevel(std::vector<std::string> args)
{
    args = args;
}

void GuiConnect::getPlayerLevel(std::vector<std::string> args)
{
    args = args;
}

std::shared_ptr<Zappy::Player> getPlayerByNb(int playerNb)
{
    playerNb = playerNb;
    return nullptr;
}