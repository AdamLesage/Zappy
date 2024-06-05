/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PNW
*/

#ifndef PNW_HPP_
#define PNW_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PNW : public ACommand {
        public:
            PNW();
            ~PNW();

            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PNW_HPP_ */
