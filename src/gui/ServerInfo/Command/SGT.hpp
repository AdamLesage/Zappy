/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** SGT
*/

#ifndef SGT_HPP_
#define SGT_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class SGT : public ACommand {
        public:
            SGT();
            ~SGT();

            void askCommand(int socket, std::vector<std::string> args);
        protected:
        private:
    };
}

#endif /* !SGT_HPP_ */
