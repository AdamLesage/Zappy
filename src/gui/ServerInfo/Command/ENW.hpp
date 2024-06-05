/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ENW
*/

#ifndef ENW_HPP_
#define ENW_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class ENW : public ACommand {
        public:
            ENW();
            ~ENW();

            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !ENW_HPP_ */
