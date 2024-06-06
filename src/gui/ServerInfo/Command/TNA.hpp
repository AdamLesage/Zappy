/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TNA
*/

#ifndef TNA_HPP_
#define TNA_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class TNA : public ACommand {
        public:
            TNA();
            ~TNA();

            std::vector<std::string> receiveData(std::string message, std::string commandName) override;
            void askCommand(int socket, std::vector<std::string> args);
        protected:
        private:
    };
}

#endif /* !TNA_HPP_ */
