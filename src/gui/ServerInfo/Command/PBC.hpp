/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#ifndef PBC_HPP_
#define PBC_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PBC : public ACommand {
        public:
            PBC();
            ~PBC();

            std::vector<std::string> receiveData(std::string message);
            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PBC_HPP_ */
