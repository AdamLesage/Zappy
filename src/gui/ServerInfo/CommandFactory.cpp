/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandFactory
*/

#include "CommandFactory.hpp"

// Include all commands
#include "./Command/PPO.hpp"
#include "./Command/MSZ.hpp"

Zappy::CommandFactory::CommandFactory(int serverSocket)
{
    _serverSocket = serverSocket;

    // Register all commands
    registerCommand("ppo", std::make_shared<PPO>());
    registerCommand("msz", std::make_shared<MSZ>());
}

Zappy::CommandFactory::~CommandFactory()
{
}

void Zappy::CommandFactory::registerCommand(std::string commandName, std::shared_ptr<ICommand> command)
{
    _commands[commandName] = command;
}

template<typename T>
T Zappy::CommandFactory::executeCommand(std::string commandName, std::string message)
{
    if (_commands.find(commandName) != _commands.end()) { // if command exists
        return _commands[commandName]->execute(message);
    }
}

void Zappy::CommandFactory::askCommand(std::string commandName, std::vector<std::string> args)
{
    if (_commands.find(commandName) != _commands.end()) { // if command exists
        _commands[commandName]->askCommand(_serverSocket, args);
    }
}
