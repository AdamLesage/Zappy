/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#ifndef PGT_HPP_
#define PGT_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PGT : public ACommand {
        public:
            PGT();
            ~PGT();

            std::vector<std::string> receiveData(std::string message);
            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PGT_HPP_ */
