/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#ifndef PDR_HPP_
#define PDR_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PDR : public ACommand {
        public:
            PDR();
            ~PDR();

            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PDR_HPP_ */
