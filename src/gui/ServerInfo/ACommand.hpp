/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ACommand
*/

#ifndef ACOMMAND_HPP_
#define ACOMMAND_HPP_

#include "ICommand.hpp"

namespace Zappy {
    class ACommand : public ICommand {
        public:
            ACommand() {}
            ~ACommand() {}

            virtual std::vector<std::string> receiveData(std::string message) = 0;
            virtual void askCommand(int socket, std::vector<std::string> args) = 0;
        protected:
        private:
    };
}

#endif /* !ACOMMAND_HPP_ */
