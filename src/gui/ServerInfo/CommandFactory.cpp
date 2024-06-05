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
#include "./Command/PNW.hpp"
#include "./Command/TNA.hpp"
#include "./Command/PLV.hpp"
#include "./Command/PIN.hpp"
#include "./Command/PEX.hpp"
#include "./Command/PBC.hpp"
#include "./Command/PIC.hpp"
#include "./Command/PIE.hpp"

Zappy::CommandFactory::CommandFactory(int serverSocket)
{
    _serverSocket = serverSocket;

    // Register all commands
    registerCommand("ppo", std::make_shared<PPO>());
    registerCommand("msz", std::make_shared<MSZ>());
    registerCommand("pnw", std::make_shared<PNW>());
    registerCommand("tna", std::make_shared<TNA>());
    registerCommand("plv", std::make_shared<PLV>());
    registerCommand("pin", std::make_shared<PIN>());
    registerCommand("pex", std::make_shared<PEX>());
    registerCommand("pbc", std::make_shared<PBC>());
    registerCommand("pic", std::make_shared<PIC>());
    registerCommand("pie", std::make_shared<PIE>());
}

Zappy::CommandFactory::~CommandFactory()
{
}

void Zappy::CommandFactory::registerCommand(std::string commandName, std::shared_ptr<ICommand> command)
{
    _commands[commandName] = command;
}

std::vector<std::string> Zappy::CommandFactory::executeCommand(std::string commandName, std::string message)
{
    if (_commands.find(commandName) != _commands.end()) { // if command exists
        return _commands[commandName]->receiveData(message);
    }
    return {};
}

void Zappy::CommandFactory::askCommand(std::string commandName, std::vector<std::string> args)
{
    if (_commands.find(commandName) != _commands.end()) { // if command exists
        _commands[commandName]->askCommand(_serverSocket, args);
    }
}
