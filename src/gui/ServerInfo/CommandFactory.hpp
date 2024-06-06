/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandFactory
*/

#ifndef COMMANDFACTORY_HPP_
#define COMMANDFACTORY_HPP_

#include <map>
#include <memory>
#include "ICommand.hpp"
#include <vector>

namespace Zappy {
    class Inventory;
    class Player;
    class Egg;
    class Tile;

    class CommandFactory {
        public:
            CommandFactory(int serverSocket);
            ~CommandFactory();

            void registerCommand(std::string commandName, std::shared_ptr<ICommand> command);
            void executeCommand(std::string commandName, std::string message,
                                            std::array<int, 2> &size_map,
                                            std::vector<std::shared_ptr<Zappy::Tile>> &tiles,
                                            std::vector<std::shared_ptr<Zappy::Player>> &players,
                                            std::vector<std::shared_ptr<Zappy::Egg>> &eggs);
            void askCommand(std::string commandName, std::vector<std::string> args);
            bool isARegisteredCommand(std::string commandName) { return _commands.find(commandName) != _commands.end(); }
        protected:
            std::map<std::string, std::shared_ptr<ICommand>> _commands;
            int _serverSocket;
        private:
    };;
}

#endif /* !COMMANDFACTORY_HPP_ */
