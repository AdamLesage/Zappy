/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#ifndef PFK_HPP_
#define PFK_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PFK : public ACommand {
        public:
            PFK();
            ~PFK();

            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PFK_HPP_ */
