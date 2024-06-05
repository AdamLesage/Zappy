/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#ifndef PEX_HPP_
#define PEX_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PEX : public ACommand {
        public:
            PEX();
            ~PEX();

            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PEX_HPP_ */
