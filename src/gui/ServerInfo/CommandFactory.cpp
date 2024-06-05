/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandFactory
*/

#include "CommandFactory.hpp"

#include "PPO.hpp"

Zappy::CommandFactory::CommandFactory()
{
    registerCommand("ppo", std::make_shared<PPO>());
}

Zappy::CommandFactory::~CommandFactory()
{
}

void Zappy::CommandFactory::registerCommand(std::string commandName, std::shared_ptr<ICommand> command)
{
    _commands[commandName] = command;
}

void Zappy::CommandFactory::executeCommand(std::string commandName, std::string message)
{
    if (_commands.find(commandName) != _commands.end()) { // if command exists
        _commands[commandName]->execute(message);
    }
}