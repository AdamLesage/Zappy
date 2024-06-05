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
            CommandFactory();
            ~CommandFactory();

            void registerCommand(std::string commandName, std::shared_ptr<ICommand> command);
            void executeCommand(std::string commandName, std::string message);
        protected:
            std::map<std::string, std::shared_ptr<ICommand>> _commands;
        private:
    };
}

#endif /* !COMMANDFACTORY_HPP_ */
