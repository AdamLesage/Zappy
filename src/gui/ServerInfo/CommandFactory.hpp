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

namespace Zappy {
    class CommandFactory {
        public:
            CommandFactory(int serverSocket);
            ~CommandFactory();

            void registerCommand(std::string commandName, std::shared_ptr<ICommand> command);
            template<typename T>
            T executeCommand(std::string commandName, std::string message);
            void askCommand(std::string commandName, std::vector<std::string> args);
        protected:
            std::map<std::string, std::shared_ptr<ICommand>> _commands;
            int _serverSocket;
        private:
    };;
}

#endif /* !COMMANDFACTORY_HPP_ */
