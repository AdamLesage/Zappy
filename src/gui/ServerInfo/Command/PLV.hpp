/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PLV
*/

#ifndef PLV_HPP_
#define PLV_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PLV : public ACommand {
        public:
            PLV();
            ~PLV();

            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PLV_HPP_ */
